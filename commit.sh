#!/bin/bash
git add .gitignore
git add * 2> /dev/null
if [ $(git ls-files --deleted -z | grep -cP ".*") -gt 0 ]; then
	git ls-files --deleted -z | xargs -0 git rm --ignore-unmatch
fi
git commit
git push
