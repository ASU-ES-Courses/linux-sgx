TIME_BEFORE="$(sh -c 'date +%s.%N')"
./app
TIME_AFTER="$(sh -c 'date +%s.%N')"
echo 'Before: ' $TIME_BEFORE
echo 'After:  ' $TIME_AFTER


