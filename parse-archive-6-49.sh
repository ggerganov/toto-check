#!/bin/bash

for i in `seq 1958 2019` ; do
    cat data/6-49/archive-${i}.txt | sed 's/[^[0-9]]*/ /g' | grep -v -e '^$' | sed -e "s/^/$i /" | sed -e "s/\s*$//"
done
