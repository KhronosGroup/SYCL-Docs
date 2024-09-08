#!/usr/bin/env bash

error=0
for file in adoc/chapters/*.adoc adoc/extensions/*.adoc;
do
  echo "$file"
  dir=`dirname $file`
  dir=`basename $dir`
  ./adoc/scripts/reflow.py -out "tmp_ci/$dir" -- "$file"
  diff "$file" "${file/adoc/tmp_ci}"
  error=$((error+$?))
done

exit $error
