#!/bin/bash

# toto 2 - 6/49 is played every thursday and sunday at 17:50
# we add the following cronjobs to fetch the latest results and
# add them to the archive:
#
#  m h dom mon dow user	command
# 30 18   * * Thu root    /path/to/toto-check/cron-6-49.sh > /dev/null
# 30 18   * * Sun root    /path/to/toto-check/cron-6-49.sh > /dev/null
#

cd "$(dirname "$0")"

archive="./data/6-49/archive-all.txt"
last=`tail -n 1 $archive`

last_issue=`echo $last | awk '{print $2}'`

echo "last issue in archive : $last_issue"

new_data=`./get-latest-toto-bg-6-49.sh`

new_issue=`echo $new_data | awk '{print $2}'`

echo "newest issue : $new_issue"

if [ $new_issue != $last_issue ] ; then
    echo "adding data to archive"

    echo $new_data | sed -e "s/.*\.//" >> $archive
fi

# make sure build folder is available
cd build
./bin/reload-archive-6-49
