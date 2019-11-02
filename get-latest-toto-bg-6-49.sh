#!/bin/bash

#curl -s http://www.toto.bg | grep class=\"tiraj\" | awk '{print $5}'
dump=`curl -s http://www.toto.bg | grep --after-context=30 class=\"tiraj\"`

issue=`echo $dump | grep class=\"tiraj\" | awk '{print $3}'`
date=`echo $dump | grep class=\"tiraj\" | awk '{print $5}' | sed -e "s/<.*//"`
nums=`echo "$dump" | grep ball-white | head -n 6 | sed -s "s/.*\;\">//" | sed -e "s/<.*//"`

echo "$date $issue"
echo "$nums"
