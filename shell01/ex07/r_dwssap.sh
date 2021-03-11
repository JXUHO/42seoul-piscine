cat /etc/passwd | awk '!/#/' | awk "NR % 2 == 0" | cut -d : -f1 | rev | sort -r | awk -v from=$FT_LINE1 -v to=$FT_LINE2 'NR==from,NR==to' | tr '\n' ', ' | sed 's/,$/./' | tr -d '\n'
