# Bourne-again shell master in 15 minutes
## What is bash?
Bash is Unix shell and command language, among many other shell scripting languages is most widespread.
## How to use it
Usually use console or terminal or ssh connection. You can directly put in commands one line at a time. For example,  `echo` command is used to print text:
 ```shell
user@unix_pc:~$ echo "hello there"
hello there
```
To execute batch of comands, save it into a file (e.g. `something.sh` containing exact formula above) and execute it, for example:
```shell
user@unix_pc:~$ bash something.sh
hello there
```
### Comment
to ensure your script will be readable, you should describe what are you doing in comments. In bash they are separated with `#`, fr example:
```shell
user@unix_pc:~$ echo "only this will be printed" # echo "this will not"
only this will be printed
```

## Variables
to avoid typing in everything manually you can use **variables**, example:
```shell
user@unix_pc:~$ NAME="John"
user@unix_pc:~$ echo "Hello $NAME!"
Hello John!
```
to assign output of different command or program to variable, use `$(command)` or ``` `command` ```syntax, for example saving current directory, `pwd` into variable and using it:
```shell
user@unix_pc:~$ CUR_DIR=$(pwd)
user@unix_pc:~$ echo "Hello I am in $CUR_DIR"
Hello I am in /home/user
```

## Expansions
There are multiple expansions which help you manipulate texts, strings, attributes...
### Brace expansions
The bash posses possibility to easily generate set of strings via braces, example:
```shell
user@unix_pc:~$ echo A{b,c,d}E
AbE AcE AdE
user@unix_pc:~$ echo "#"{1,2,3}{A,B,C}
#1A #1B #1C #2A #2B #2C #3A #3B #3C
user@unix_pc:~$ echo file_{1..9}.txt
file_1.txt file_2.txt file_3.txt file_4.txt file_5.txt file_6.txt file_7.txt file_8.txt file_9.txt
```
### Parameter Expansions and text manipulation
#### Cutting/slicing
You can easily manipulate existing string via slicing, substitution, cutting. To do so you may use letter index which is letter's number representation from the beginning of the text:

Text `Hello !`|H|e|l|l|o| |!
-|-|-|-|-|-|-|-
ID from the beginning|0|1|2|3|4|5|6
ID from the end|-7|-6|-5|-4|-3|-2|-1|

Example worth thousand words:
```shell
user@unix_pc:~$ text="Hello there, I am John Doe" # assign variable
user@unix_pc:~$ echo ${text::5} # print first 5 letters
Hello
user@unix_pc:~$ echo ${text::-3} # print everything but last 3 letters
Hello there, I am John
user@unix_pc:~$ echo ${text:(-3)} # print everything after letter 3 letters before end
Doe
user@unix_pc:~$ echo ${text:12:-3} # print everything 12 letters from beginning up to 3 from letters end
I am John
```

#### Text manipulation and letter replacement
Sometimes you want to have text only in upper/lower case or you want to replace sme letters, this example becomes handy:
```shell
# Manipulation
user@unix_pc:~$ echo ${text^^} # all Uppercase
HELLO THERE, I AM JOHN DOE
user@unix_pc:~$ echo ${text,,} # all Lowercase
hello there, i am john doe

# Replacement
user@unix_pc:~$ echo ${text/J/j} # replace first "J" with "j"
Hello there, I am john Doe
user@unix_pc:~$ echo ${text//o/O} # replace all "o"s with "O"
HellO there, I am JOhn DOe
user@unix_pc:~$ text2="...Hello again..."
user@unix_pc:~$ echo ${text2#...} # remove ... from beginning only
Hello again...
user@unix_pc:~$ echo ${text2%..} # remove .. from end only
...Hello again.
user@unix_pc:~$ echo ${text2//./} # replace all . with nothing, thus remove them
Hello again
user@unix_pc:~$ echo ${text2//./}" Dude!" # and append something to it
Hello again Dude!
```

#### Default values and errors
If you want to avoid mistakes or prepare your script for inexperienced user, default values are good way to go:
```shell
user@unix_pc:~$ echo ${FOO:?"Variable is not set..."}
bash: FOO2: Variable is not set...
user@unix_pc:~$ FOO=$RANDOM
user@unix_pc:~$ echo ${FOO:?"Variable is not set..."}
23732
user@unix_pc:~$ echo ${BAR-"default"} # print "default" if BAR is not set
default
user@unix_pc:~$ BAR=$RANDOM
user@unix_pc:~$ echo ${BAR-"default"} # print BAR's value if exists
15399
user@unix_pc:~$ echo ${BAR+"conditional"} # print "conditional" only if BAR exists, nothing otherwise
conditional
user@unix_pc:~$ unset BAR # unset variable
user@unix_pc:~$ echo ${BAR="default"} # print default value and assign it to BAR
default

```

#### Miscelaneous
various handy tools how to get additional information of variables, files....
```shell
user@unix_pc:~$ echo ${#text} # get the length of text
30

user@unix_pc:~$ FILE=$(pwd)"/ping.log" # get full path to file ping.log
user@unix_pc:~$ echo $FILE
/home/user/ping.log
user@unix_pc:~$ BASE=${FILE##*/} # remove everything before last "/" (including)
user@unix_pc:~$ echo $BASE
ping.log
user@unix_pc:~$ FILENAME=${FILE%$BASE} # remove BASE and leave only filename
user@unix_pc:~$ echo $FILENAME
/home/user/
user@unix_pc:~$ FILENAME2=${FILE%/*} # which is equivalent to this
user@unix_pc:~$ echo $FILENAME2
/home/user
```

## Conditions
as any other scripting language, bash implements conditional program flow, syntax is basically:
```shell
if command1; then # if this condition is met
    echo "execute some command"
elif command3; then # if this condition is met
    echo "execute something else"
else # if no condition is met
    echo "execute something different"
fi
```
for example, testing internet connection can be done via command `ping` the following way:
```shell
if ping -c1 google.com; then # try to ping google.com
    echo "Connected to internet"
elif ping -c1 8.8.8.8; then # if failed, try it using direct ip
    echo "Connected to internet but without valid DNS"
else # everything failed, user is disconnected
    echo "Disconnected from internet"
fi
```

### Conditional execution
you can easily chain commands, one depending on another with **and** or **or** statements, `&&` or `||` respectively:
```shell
# returns True only if both commands execute successfully
git commit && git push
# returns True if one of commands execute successfully
# if first is executed successfully not proceed to other one
# because its not necessary
git commit || echo "Commit failed"
```

### [[ expression ]]
to check some basic properties or compare variables it is handy to use [[ ... ]] syntax. It is executed as any other program, better to see the example:
```shell
# String
if [[ -z "$string" ]]; then
  echo "String is empty"
elif [[ -n "$string" ]]; then
  echo "String is not empty"
fi
```
#### list of most useful expressions:
```shell
# string conditions
[[ -z STRING ]] # Empty string
[[ -n STRING ]] # Not empty string
[[ STRING == STRING ]] # Equal
[[ STRING != STRING ]] # Not Equal
[[ STRING =~ STRING ]] # Regexp

# number comparison
[[ NUM -eq NUM ]] # Equal
[[ NUM -ne NUM ]] # Not equal
[[ NUM -lt NUM ]] # Less than
[[ NUM -le NUM ]] # Less than or equal
[[ NUM -gt NUM ]] # Greater than
[[ NUM -ge NUM ]] # Greater than or equal
(( NUM < NUM )) # Numeric conditions
[[ -o noclobber ]] # If OPTIONNAME is enabled

# adv. conditions
[[ ! EXPR ]] # Not
[[ X ]] && [[ Y ]] # And
[[ X ]] || [[ Y ]] # Or

# File conditions
[[ -e FILE ]] # Exists
[[ -r FILE ]] # Readable
[[ -h FILE ]] # Symlink
[[ -d FILE ]] # Directory
[[ -w FILE ]] # Writable
[[ -s FILE ]] # Size is > 0 bytes
[[ -f FILE ]] # File
[[ -x FILE ]] # Executable
[[ FILE1 -nt FILE2 ]] # 1 is more recent than 2
[[ FILE1 -ot FILE2 ]] # 2 is more recent than 1
[[ FILE1 -ef FILE2 ]] # Same files
```
#### examples
```shell
# Combinations
if [[ X ]] && [[ Y ]]; then
  ...
fi

if (( $a < $b )); then
   echo "$a is smaller than $b"
fi

if [[ -e "file.txt" ]]; then
  echo "file exists"
fi
```

# Redirection
Bash uses 3 standard streams of informations.

stream            |description
------------------|------------------------
<kbd>STDOUT</kbd> |standard output of application
<kbd>STDERR</kbd> |errors from program run
<kbd>STDIN</kbd>  |standard input for application

To efficiently work with [modular structure of unix](https://en.wikipedia.org/wiki/Unix_philosophy) you may redirect <kbd>STDOUT</kbd> of one program and use it as input of another or save it as a file instead of printing it out with following syntax:
```shell
command1 | command2 # execute command1 and it's output use as input for command2
command1 > file.txt # execute command1 and save output to file.txt, rewrite the file
command1 >> file.txt # execute command1 and save output to file.txt, append the text to end of file
```
For example, `cat` program reads <kbd>STDIN</kbd> of multiple files and prints them to <kbd>STDOUT</kbd>, `grep` program finds text in file/stream
```shell
user@unix_pc:~$ ping -c1 google.com 1>ping.log# ping google 1x, save stats to "ping.log"
user@unix_pc:~$ ping -c4 google.com 1>>ping.log# ping google 4x, append stats to "ping.log"
user@unix_pc:~$ cat ping.log|grep "packet loss" # search for packet loss inside log
1 packets transmitted, 1 received, 0% packet loss, time 0ms
4 packets transmitted, 4 received, 0% packet loss, time 8ms
```

lets extend conditional expression from previous chapter:
```shell
if ping -c1 google.com 1>/dev/null; then # try to ping google.com, redirect STDOUT to /dev/null "bottomless pit"
    echo "Connected to internet"
else # everything failed, user is disconnected
    echo "Disconnected from internet"
fi
```
now you should see only relevant information without statistics

## To do
* functions
* loops
* case/switch
* history
* arrays
* dictionaries

## Sources
based on:
1. [learnXinYminutes](https://learnxinyminutes.com/docs/bash/)
1. [bash-hackers](https://wiki.bash-hackers.org/)
1. [devhints/bash](https://devhints.io/bash)

---
_Sorry for mistakes, didn't read much after myself_
