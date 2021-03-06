#!/bin/bash
##---------------------------------------------------------------------------##
## File  : regression/ml-job-launch.sh
## Date  : Tuesday, May 31, 2016, 14:48 pm
## Author: Kelly Thompson
## Note  : Copyright (C) 2016, Los Alamos National Security, LLC.
##         All rights are reserved.
##---------------------------------------------------------------------------##

# called from regression-master.sh
# assumes the following variables are defined in regression-master.sh:
#    $regdir     - /scratch/regress
#    $rscriptdir - /scratch/regress/draco/regression (actually, the location
#                  where the active regression_master.sh is located)
#    $subproj    - 'draco', 'jaynne', 'capsaicin', etc.
#    $build_type - 'Debug', 'Release'
#    $extra_params - '', 'intel13', 'pgi', 'coverage'

# command line arguments
args=( "$@" )
nargs=${#args[@]}
scriptname=${0##*/}
host=`uname -n`

export MOABHOMEDIR=/opt/MOAB
extradirs="/opt/MOAB/bin /opt/MOAB/default/bin"
for mydir in ${extradirs}; do
   if test -z "`echo $PATH | grep $mydir`" && test -d $mydir; then
      export PATH=${PATH}:${mydir}
   fi
done
export SHOWQ=`which showq`

# Dependencies: wait for these jobs to finish
dep_jobids=""
for (( i=0; i < $nargs ; ++i )); do
   dep_jobids="${dep_jobids} ${args[$i]} "
done

# sanity check
if [[ ! ${regdir} ]]; then
    echo "FATAL ERROR in ${scriptname}: You did not set 'regdir' in the environment!"
    exit 1
fi
if [[ ! ${rscriptdir} ]]; then
    echo "FATAL ERROR in ${scriptname}: You did not set 'rscriptdir' in the environment!"
    exit 1
fi
if [[ ! ${subproj} ]]; then
    echo "FATAL ERROR in ${scriptname}: You did not set 'subproj' in the environment!"
    exit 1
fi
if [[ ! ${build_type} ]]; then
    echo "FATAL ERROR in ${scriptname}: You did not set 'build_type' in the environment!"
    exit 1
fi
if [[ ! ${logdir} ]]; then
    echo "FATAL ERROR in ${scriptname}: You did not set 'logdir' in the environment!"
    exit 1
fi

if test $subproj == draco || test $subproj == jayenne; then
  if [[ ! ${featurebranch} ]]; then
    echo "FATAL ERROR in ${scriptname}: You did not set 'featurebranch' in the environment!"
    echo "printenv -> "
    printenv
  fi
fi

# What queue should we use?
avail_queues=`mdiag -u $LOGNAME | grep ALIST | sed -e 's/.*ALIST=//' | sed -e 's/,/ /g'`
case $avail_queues in
*access*) access_queue="-A access" ;;
esac

# Banner
echo "==========================================================================="
echo "ML Regression job launcher for ${subproj} - ${build_type} flavor."
echo "==========================================================================="
echo " "
echo "Environment:"
echo "   subproj        = ${subproj}"
echo "   build_type     = ${build_type}"
if [[ ! ${extra_params} ]]; then
  echo "   extra_params   = none"
else
  echo "   extra_params   = ${extra_params}"
fi
if [[ ${featurebranch} ]]; then
  echo "   featurebranch  = ${featurebranch}"
fi
echo "   regdir         = ${regdir}"
echo "   rscriptdir     = ${rscriptdir}"
echo "   scratchdir     = ${scratchdir}"
echo "   logdir         = ${logdir}"
echo "   dashboard_type = ${dashboard_type}"
echo "   build_autodoc  = ${build_autodoc}"
echo "   MOAB queue     = ${access_queue}"
echo " "
echo "   ${subproj}: dep_jobids = ${dep_jobids}"
echo " "

echo "module purge &> /dev/null"
module purge &> /dev/null

# Prerequisits:
# Wait for all dependencies to be met before creating a new job

for jobid in ${dep_jobids}; do
    while [ `ps --no-headers -u ${USER} -o pid | grep -c ${jobid}` -gt 0 ]; do
       echo "   ${subproj}: waiting for jobid = $jobid to finish (sleeping 5 min)."
       sleep 5m
    done
done

if ! test -d $logdir; then
  mkdir -p $logdir
  chgrp draco $logdir
  chmod g+rwX $logdir
  chmod g+s $logdir
fi

# Configure on the front end
echo "Configure:"
export REGRESSION_PHASE=c
cmd="${rscriptdir}/ml-regress.msub >& ${logdir}/${machine_name_short}-${subproj}-${build_type}${epdash}${extra_params}${prdash}${featurebranch}-${REGRESSION_PHASE}.log"
echo "${cmd}"
eval "${cmd}"

# Build, Test on back end
echo " "
echo "Build, Test:"
export REGRESSION_PHASE=bt
cmd="/opt/MOAB/bin/msub ${access_queue} -j oe -V -o ${logdir}/${machine_name_short}-${subproj}-${build_type}${epdash}${extra_params}${prdash}${featurebranch}-bt.log ${rscriptdir}/ml-regress.msub"
echo "${cmd}"
jobid=`eval ${cmd}`
# trim extra whitespace from number
jobid=`echo ${jobid//[^0-9]/}`

# Wait for BT (build and test) to finish
sleep 1m
while test "`$SHOWQ | grep $jobid`" != ""; do
   $SHOWQ | grep $jobid
   sleep 5m
done

# Submit from the front end
echo " "
echo "Submit:"
export REGRESSION_PHASE=s
echo "Jobs done, now submitting ${build_type} results from ${host}."
cmd="${rscriptdir}/ml-regress.msub >& ${logdir}/${machine_name_short}-${subproj}-${build_type}${epdash}${extra_params}${prdash}${featurebranch}-s.log"
echo "${cmd}"
eval "${cmd}"

echo "All done."

##---------------------------------------------------------------------------##
## End of ml-job-launch.sh
##---------------------------------------------------------------------------##
