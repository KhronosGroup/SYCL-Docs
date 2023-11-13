#!/usr/bin/env bash

error=0
for file in adoc/chapters/*.adoc;
do
  echo "$file"
  ./adoc/scripts/reflow.py -out tmp_ci/ -- "$file"
  diff "$file" "${file/adoc\/chapters/tmp_ci}"
  error=$((error+$?))
done

exit $error
