# -*- mode:sh -*-

# Use: In ~/.cshrc add the following code:
#
# setenv DRACO_DIR ~/draco
# source $DRACO_DIR/environment/cshrc/.cshrc
#

setenv PATH $DRACO_DIR/environment/bin:$PATH

# Extra module stuff
switch ("`uname -n`")
case tu*.lanl.gov:
case tu*.localdomain:
    source /usr/projects/crestone/dotfiles/Cshrc
    module use $DRACO_DIR/environment/Modules/hpc
    module use $DRACO_DIR/environment/Modules/tu-fe
    module load friendly-testing hpc-tools
    module load intel-c intel-f openmpi-intel
    module load gsl/1.14-intel
    module load lapack/atlas-3.8.3-intel emacs 
    module load cmake numdiff git xshow papi
    breaksw
case yr*.lanl.gov:
case yr*:
    source /usr/projects/crestone/dotfiles/Cshrc
    module use $DRACO_DIR/environment/Modules/hpc
    module use $DRACO_DIR/environment/Modules/yr-fe
    module load lapack/atlas-3.8.3 
    module load cmake numdiff git xshow
    module load gsl/1.14-pgi emacs
    breaksw
case ct*:
   # source /usr/projects/crestone/dotfiles/Cshrc
   module use $DRACO_DIR/environment/Modules/hpc
   module use $DRACO_DIR/environment/Modules/ct-fe
   module load gsl/1.15
   module load cmake numdiff git xshow
   breaksw
case rr-dev*:
case rra[0-9][0-9][0-9]a*:
   source /usr/projects/crestone/dotfiles/Cshrc
   module use $DRACO_DIR/environment/Modules/hpc
   module use $DRACO_DIR/environment/Modules/rr-dev-fe
   module load hpc-tools friendly-testing cellsdk
   module unload pgi 
   module load cmake numdiff git xshow python
   breaksw
case rra[0-9][0-9][0-9][bcd]*:
   # source /usr/projects/crestone/dotfiles/Cshrc
   module use $DRACO_DIR/environment/Modules/ppc64
   module load hpc-tools friendly-testing cellsdk
   module load cmake gsl-1.14 numdiff 
   module load 
   breaksw
endsw

# Set term title
set myhost=`echo $HOST | sed -e 's/[.].*//g'`

# Aliases
alias btar 'tar --use-compress-program /usr/bin/bzip2'
alias cd.. 'cd ..'
alias cpuinfo 'cat /proc/cpuinfo'
alias cvsup 'cvs -q update -AdP'
alias df 'df -h'
alias dirs 'dirs -v'
alias dmesg 'dmesg -s 65536'
alias du 'du -s -h'
alias em 'emacs $* -g 90x55'
alias free 'free -m'
alias hosts 'cat /etc/hosts'
alias hpss 'echo Try using psi instead of hpss'
alias l. 'ls --color -aFl'
alias ldmesg 'dmesg -s 65536 | less'
alias less '/usr/bin/less -r'
alias ll 'ls --color -Fl'
alias ls 'ls --color -F'
alias lt 'ls --color -Flt'
alias lt. 'ls --color -aFlt'
alias mdstat 'cat /proc/mdstat'
alias meminfo 'cat /proc/meminfo'
alias mroe 'more'
alias print 'lp'
alias resettermtitle 'echo -ne "\033]0;${myhost}\007"'
alias rtt 'echo -ne "\033]0;${myhost}\007"'
alias sdk 'export DISPLAY 128.165.87.170:0.0;echo The DISPLAY value is now: $DISPLAY'
alias sdl 'DISPLAY 127.0.0.1:0.0;echo The DISPLAY value is now: $DISPLAY'
alias vi 'vim'
alias watchioblocks 'ps -eo stat,pid,user,command | egrep "^STAT|^D|^R"'
alias which 'alias | /usr/bin/which --tty-only --read-alias --show-dot --show-tilde'
alias wmdstat 'watch -n 2 "cat /proc/mdstat"'
alias xload 'xload -label ${myhost}'

# CVS
setenv CVS_RSH ssh
setenv CVSROOT ccscs9:/ccs/codes/radtran/cvsroot