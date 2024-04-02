
# Shelly


## SYNOPSIS

Shelly is a simple UNIX command interpreter written in C language. 

## DESCRIPTION

A prompt is displayed and then waits for the user to type a command. A command line always ends with a new line. The prompt will display anew each time a command has been executed. The command lines are simple—no semicolons, no pipes, no redirections or any other advanced features. The command can be made up multiple arguments. The first argument is the executable or built-in function the user wishes to use, and additional arguments will act as parameters specified for the first. If an executable cannot be found, an error message will print and display the prompt again. It will handle errors. If no text is entered following a new prompt, the user can exit by pressing Ctrl+D.

Shelly works similarly to sh, bash, and other basic shells.

The shell is compiled using an Ubuntu 22.04 LTS machine with: 
gcc -Wall -Werror -Wextra -pedantic -std=gnu89

## BUILT-INS

| **Built-ins** | **Result** |
| ----- | --------------------------- |
| env | Prints the environmental variables  |
| exit | Exits the shell |

## USAGE

Shelly can be run interactively or non-interactively.  
In interactive mode, the "$" prompt is printed and then waits for user input.  
In non-interactive mode, the prompt is not printed and input is processed immediately.

### Example invocation

An interactive mode example:

    $ ls -l /usr/local

To run in non-interactive mode, the user could instead, for example, pipe in commands when launching Shelly from another shell:

    $ echo "ls -l /usr/local" | ./hsh

In both examples, this returns something along the following:
```
total 32
drwxr-xr-x 2 root root 4096 Mar 31 21:27 bin
drwxr-xr-x 2 root root 4096 Mar  8  2023 etc
drwxr-xr-x 2 root root 4096 Mar  8  2023 games
drwxr-xr-x 2 root root 4096 Mar  8  2023 include
drwxr-xr-x 3 root root 4096 Mar  8  2023 lib
lrwxrwxrwx 1 root root    9 Mar  8  2023 man -> share/man
drwxr-xr-x 2 root root 4096 Mar  8  2023 sbin
drwxr-xr-x 8 root root 4096 Mar 23 14:16 share
drwxr-xr-x 2 root root 4096 Mar  8  2023 src
```

### Built-in Example

<details>
<summary>Here is how to utilize the "env" built-in function in interactive mode</summary>
<br>
Input:
    
    $ env
Output:
<br><br>
<pre>
SYSTEMD_EXEC_PID=2203
SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
SESSION_MANAGER=local/pop-os:@/tmp/.ICE-unix/2179,unix/pop-os:/tmp/.ICE-unix/2179
GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/7c3c87cf_dfbc_4110_96e0_9b8a6ec97ec4
LANG=en_US.UTF-8
XDG_CURRENT_DESKTOP=pop:GNOME
QT_IM_MODULE=ibus
GPG_AGENT_INFO=/run/user/1000/gnupg/S.gpg-agent:0:1
DESKTOP_SESSION=pop
USER=ezbz
XDG_MENU_PREFIX=gnome-
HOME=/home/ezbz
MOZ_USE_XINPUT2=1
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
SSH_AGENT_LAUNCHER=gnome-keyring
GTK_MODULES=gail:atk-bridge
XDG_CONFIG_DIRS=/etc/xdg/xdg-pop:/etc/xdg
GTK_IM_MODULE=ibus
XDG_SESSION_DESKTOP=pop
QT_ACCESSIBILITY=1
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
WINDOWPATH=2
LOGNAME=ezbz
GNOME_TERMINAL_SERVICE=:1.198
VTE_VERSION=6800
PATH=/home/ezbz/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/ezbz/.local/bin
XDG_RUNTIME_DIR=/run/user/1000
XMODIFIERS=@im=ibus
SHELL=/usr/bin/zsh
XDG_SESSION_TYPE=x11
GNOME_SHELL_SESSION_MODE=pop
XDG_DATA_DIRS=/usr/share/pop:/usr/share/gnome:/home/ezbz/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share/:/usr/share/
USERNAME=ezbz
COLORTERM=truecolor
XAUTHORITY=/run/user/1000/gdm/Xauthority
PWD=/home/ezbz/Code/Local/atlas-simple_shell
XDG_SESSION_CLASS=user
TERM=xterm-256color
GDMSESSION=pop
DISPLAY=:1
SHLVL=1
OLDPWD=/home/ezbz/Code/Local/atlas-simple_shell/.extra
ZSH=/home/ezbz/.oh-my-zsh
PAGER=less
LESS=-R
LSCOLORS=Gxfxcxdxbxegedabagacad
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
_=/home/ezbz/Code/Local/atlas-simple_shell/./
</pre>
</details>

## RETURN VALUE

Upon successful execution, Shelly returns a value of 0, or 1 if the command failed.

## FLOWCHART

![shelly flowchart](./assets/shelly_flowchart.png "simple shell flowchart")
