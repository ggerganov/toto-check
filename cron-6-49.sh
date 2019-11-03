#!/bin/bash

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

cd build
./bin/reload-archive-6-49
