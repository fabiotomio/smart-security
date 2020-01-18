#! /bin/sh

echo "Watching file changes in ./main folder\n"

fswatch -e "build" ./main | xargs -I{} sh -c 'echo "File {} changed\n";  make all'