#!/bin/bash

year=1958
for url in \
/content/files/stats-tiraji/649_58.txt \
/content/files/stats-tiraji/649_59.txt \
/content/files/stats-tiraji/649_60.txt \
/content/files/stats-tiraji/649_61.txt \
/content/files/stats-tiraji/649_62.txt \
/content/files/stats-tiraji/649_63.txt \
/content/files/stats-tiraji/649_64.txt \
/content/files/stats-tiraji/649_65.txt \
/content/files/stats-tiraji/649_66.txt \
/content/files/stats-tiraji/649_67.txt \
/content/files/stats-tiraji/649_68.txt \
/content/files/stats-tiraji/649_69.txt \
/content/files/stats-tiraji/649_70.txt \
/content/files/stats-tiraji/649_71.txt \
/content/files/stats-tiraji/649_72.txt \
/content/files/stats-tiraji/649_73.txt \
/content/files/stats-tiraji/649_74.txt \
/content/files/stats-tiraji/649_75.txt \
/content/files/stats-tiraji/649_76.txt \
/content/files/stats-tiraji/649_77.txt \
/content/files/stats-tiraji/649_78.txt \
/content/files/stats-tiraji/649_79.txt \
/content/files/stats-tiraji/649_80.txt \
/content/files/stats-tiraji/649_81.txt \
/content/files/stats-tiraji/649_82.txt \
/content/files/stats-tiraji/649_83.txt \
/content/files/stats-tiraji/649_84.txt \
/content/files/stats-tiraji/649_85.txt \
/content/files/stats-tiraji/649_86.txt \
/content/files/stats-tiraji/649_87.txt \
/content/files/stats-tiraji/649_88.txt \
/content/files/stats-tiraji/649_89.txt \
/content/files/stats-tiraji/649_90.txt \
/content/files/stats-tiraji/649_91.txt \
/content/files/stats-tiraji/649_92.txt \
/content/files/stats-tiraji/649_93.txt \
/content/files/stats-tiraji/649_94.txt \
/content/files/stats-tiraji/649_95.txt \
/content/files/stats-tiraji/649_96.txt \
/content/files/stats-tiraji/649_97.txt \
/content/files/stats-tiraji/649_98.txt \
/content/files/stats-tiraji/649_99.txt \
/content/files/stats-tiraji/649_00.txt \
/content/files/stats-tiraji/649_01.txt \
/content/files/stats-tiraji/649_02.txt \
/content/files/stats-tiraji/649_03.txt \
/content/files/stats-tiraji/649_04.txt \
/content/files/stats-tiraji/649_2005.txt \
/content/files/stats-tiraji/649_2006.txt \
/content/files/stats-tiraji/649_2007.txt \
/content/files/stats-tiraji/649_2008.txt \
/content/files/stats-tiraji/649_2009.txt \
/content/files/stats-tiraji/649_2010.txt \
/content/files/stats-tiraji/649_2011.txt \
/content/files/stats-tiraji/649_2012.txt \
/content/files/stats-tiraji/649_2013.txt \
/content/files/stats-tiraji/649_2014.txt \
/content/files/stats-tiraji/649_2015.txt \
/content/files/stats-tiraji/649_2016.txt \
/content/files/2018/01/26/2a0952991d371ca5575a4d79e5c5e5d5.txt \
/content/files/2019/02/16/be9d1b15257f53cd749db1e501b01180.txt ; do
    echo $year - $url
    wget  -O ./data/6-49/archive-$year.txt http://www.toto.bg/$url
    year=$[$year+1]
    sleep 1
done
