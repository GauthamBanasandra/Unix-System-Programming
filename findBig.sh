#ls -l

# remove the first line
#ls -l | tail -n +2

# break into fields
# delimiter is space here; expects tab; does not work
#ls -l | tail -n +2 | cut -f5,9

 #does not work; each space considered a delimiter
#ls -l | tail -n +2 | cut -d" " -f5,9

# remove multiple spaces
#ls -l | tail -n +2 | tr -s " " |  cut -d" " -f5,9

# arrange in order
#ls -l | tail -n +2 | tr -s " " |  cut -d" " -f5,9 | sort -n

# get the last entry
#ls -l | tail -n +2 | tr -s " " |  cut -d" " -f5,9 | sort -n | tail -1

# 
ls -l | tail -n +2 | tr -s " " |  cut -d" " -f5,9 | sort -n | tee mycp | tail -1 | cut -d" " -f2

# remove all 0 byte files
rm `ls -l | sed '1d' | awk '$5 == 0 {print $9}'`















