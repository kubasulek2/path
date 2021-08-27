
##NAME
       path - get absolute path, translate path from unix to windows and vice versa.

##SYNOPSIS
       path [OPTIONS] TARGET LINK_NAME

##DESCRIPTION
       In the 1st form, create a link to TARGET with the name LINK_NAME.  In the 2nd form, create a link to TARGET in the current directory.  In
       the 3rd and 4th forms, create links to each TARGET in DIRECTORY.  Create hard links by default, symbolic links with --symbolic.   By  de‐
       fault,  each  destination (name of new link) should not already exist.  When creating hard links, each TARGET must exist.  Symbolic links
       can hold arbitrary text; if later resolved, a relative link is interpreted in relation to its parent directory.

       Mandatory arguments to long options are mandatory for short options too.

       --backup[=CONTROL]
              make a backup of each existing destination file

       -b     like --backup but does not accept an argument

       -d, -F, --directory
              allow the superuser to attempt to hard link directories (note: will probably fail due to system restrictions, even for  the  supe‐
              ruser)

       -f, --force
              remove existing destination files

       -i, --interactive
              prompt whether to remove destinations

       -L, --logical
              dereference TARGETs that are symbolic links

       -n, --no-dereference
              treat LINK_NAME as a normal file if it is a symbolic link to a directory

       -P, --physical
              make hard links directly to symbolic links

       -r, --relative
              create symbolic links relative to link location

       -s, --symbolic
              make symbolic links instead of hard links

       -S, --suffix=SUFFIX
              override the usual backup suffix

       -t, --target-directory=DIRECTORY
              specify the DIRECTORY in which to create the links

       -T, --no-target-directory
              treat LINK_NAME as a normal file always

       -v, --verbose
              print name of each linked file

       --help display this help and exit

       --version
              output version information and exit

       The  backup suffix is '~', unless set with --suffix or SIMPLE_BACKUP_SUFFIX.  The version control method may be selected via the --backup
       option or through the VERSION_CONTROL environment variable.  Here are the values:

       none, off
              never make backups (even if --backup is given)

       numbered, t
              make numbered backups

       existing, nil
              numbered if numbered backups exist, simple otherwise

       simple, never
              always make simple backups

       Using -s ignores -L and -P.  Otherwise, the last option specified controls behavior when a TARGET is a symbolic link, defaulting to -P.

AUTHOR
       Written by Mike Parker and David MacKenzie.

REPORTING BUGS
       GNU coreutils online help: <https://www.gnu.org/software/coreutils/>
       Report ln translation bugs to <https://translationproject.org/team/>

COPYRIGHT
       Copyright © 2018 Free Software Foundation, Inc.  License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.
       This is free software: you are free to change and redistribute it.  There is NO WARRANTY, to the extent permitted by law.

SEE ALSO
       link(2), symlink(2)

       Full documentation at: <https://www.gnu.org/software/coreutils/ln>
       or available locally via: info '(coreutils) ln invocation'

GNU coreutils 8.30                                               September 2019                                                            LN(1)
