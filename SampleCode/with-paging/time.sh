vmstat 1 3
TIME_BEFORE="$(sh -c 'date +%s.%N')"
./app
TIME_AFTER="$(sh -c 'date +%s.%N')"
vmstat 1 3
echo 'Before: ' $TIME_BEFORE
echo 'After:  ' $TIME_AFTER


