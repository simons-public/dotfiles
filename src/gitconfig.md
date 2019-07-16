# .gitconfig

## apply section

    [apply]

### whitespace fix

    whitespace = fix

## core section

    [core]

### whitespace

    whitespace = space-before-tab,-indent-with-non-tab,trailing-space

### safer git rebase on macos

    trustctime = false

### speed up git status

    untrackedCache = true

## diff binaries

    [diff "bin"]
    textconv = hexdump -v -C

## autocorrect commands

    [help]
    autocorrect = 1

## push section

    [push]

### use simple push by default

    default = simple

### push relevent tags

    followTags = true

## alias section

    [alias]

### simple log

    log =  log --pretty=oneline -n 20 --graph --abbrev-commit

## include local file

    [include]
    path = ~/.gitconfig.local
    path = ~/.gituser
