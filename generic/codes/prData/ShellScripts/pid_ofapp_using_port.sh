#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#!/bin/ksh
#*******************************************************************#
# Purpose is to find the PID on which given port is active.
# Need to be root to check other folk's PID's out
#
# Note: This script gives the PID and process details which is using the port number given in argument
# ./find_PID_from_port.sh 80
#*******************************************************************#
line='-------------------------------------------------------------------------'
pids=$(/bin/ps -ef | sed 1d | awk '{print $2}')
# Prompt users or use 1st cmdline argument
if [ $# -eq 0 ]; then
read ans?"Enter port you like to know pid for: "
else
ans=$1
fi
# Check all pids for this port, then list that process
for f in $pids
do /usr/proc/bin/pfiles $f 2>/dev/null | /usr/xpg4/bin/grep -q "port: $ans"
if [ $? -eq 0 ] ; then
echo $line
echo "Port: $ans is being used by PID:\c"
/usr/bin/ps -ef -o pid -o args | egrep -v "grep|pfiles" | grep $f
fi
done
exit 0
