#!/bin/bash

function xbmc_req {
    output=$(curl -s -i -X POST --header "Content-Type: application/json" -d "$1" http://$KODI_USER:$KODI_PASS@$KODI_HOST:$KODI_PORT/jsonrpc)

    if [[ $2 = true ]];
    then
        echo $output
    fi
}

function parse_json {
    key=$1
    awk -F"[,:}]" '{for(i=1;i<=NF;i++){if($i~/'$key'\042/){print $(i+1)}}}' | tr -d '"'
}

function play_youtube {

    REGEX="^.*((youtu.be\/)|(v\/)|(\/u\/\w\/)|(embed\/)|(watch\?))\??v?=?([^#\&\?]*).*"

    ID=$1

    if [ "$ID" == "" ];
    then
        echo "Syntax $0:$1 <id|url>"
        exit
    fi

    if [[ $ID =~ $REGEX ]]; then
        ID=${BASH_REMATCH[7]}
    fi

    echo -n "Opening video id $ID on $KODI_HOST ..."

    # clear the list
    xbmc_req '{"jsonrpc": "2.0", "method": "Playlist.Clear", "params":{"playlistid":1}, "id": 1}';

    # add the video to the list
    xbmc_req '{"jsonrpc": "2.0", "method": "Playlist.Add", "params":{"playlistid":1, "item" :{ "file" : "plugin://plugin.video.youtube/?action=play_video&videoid='$ID'"}}, "id" : 1}';

    # open the video
    xbmc_req '{"jsonrpc": "2.0", "method": "Player.Open", "params":{"item":{"playlistid":1, "position" : 0}}, "id": 1}';

    echo " done."
}

function play_playlist {
    xbmc_req '{"jsonrpc": "2.0", "method": "Player.Open", "params":{"item":{"playlistid":1, "position" : 0}}, "id": 1}';
    
}

function queue_yt_videos {

    REGEX="^.*((youtu.be\/)|(v\/)|(\/u\/\w\/)|(embed\/)|(watch\?))\??v?=?([^#\&\?]*).*"

    ID=$1

    if [ "$ID" == "" ];
    then
        echo "Syntax $0:$1 <id|url>"
        exit
    fi

    if [[ $ID =~ $REGEX ]]; then
        ID=${BASH_REMATCH[7]}
    fi

    output=`xbmc_req '{"jsonrpc": "2.0", "method": "Playlist.GetItems", "params":{"playlistid":1}, "id": 99}' true`
    numberitems=`echo $output | parse_json "total"`

    echo -n "Video added to the current playlist $ID on $KODI_HOST which has ($numberitems) items..."
    # add the video to the list
    xbmc_req '{"jsonrpc": "2.0", "method": "Playlist.Add", "params":{"playlistid":1, "item" :{ "file" : "plugin://plugin.video.youtube/?action=play_video&videoid='$ID'"}}, "id" : 1}';

    echo " done."
}

function play_pause {
    # Get Active players first
    output=`xbmc_req '{"jsonrpc": "2.0", "method": "Player.GetActivePlayers", "id": 99}' true`
    player_id=`echo $output | parse_json "playerid"`
    echo "Pausing/Playing the player with ID => $player_id"
    xbmc_req '{"jsonrpc": "2.0", "method": "Player.PlayPause", "params": { "playerid": '$player_id' }, "id": 1}'
}

function stop {
    # Get Active players first
    output=`xbmc_req '{"jsonrpc": "2.0", "method": "Player.GetActivePlayers", "id": 99}' true`
    player_id=`echo $output | parse_json "playerid"`
    echo "Stopping the player with ID => $player_id"
    xbmc_req '{"jsonrpc": "2.0", "method": "Player.Stop", "params": { "playerid": '$player_id' }, "id": 1}'
}

function skip_forward {
    # Get Active players first
    output=`xbmc_req '{"jsonrpc": "2.0", "method": "Player.GetActivePlayers", "id": 99}' true`
    player_id=`echo $output | parse_json "playerid"`
    echo "Skipping forward the player with ID => $player_id"
    xbmc_req '{"jsonrpc": "2.0", "method": "Player.Seek", "params": { "playerid": '$player_id', "value" : "smallforward" }, "id": 1}'
}

function skip_backward {
    # Get Active players first
    output=`xbmc_req '{"jsonrpc": "2.0", "method": "Player.GetActivePlayers", "id": 99}' true`
    player_id=`echo $output | parse_json "playerid"`
    echo "Skipping back with the player with ID => $player_id"
    xbmc_req '{"jsonrpc": "2.0", "method": "Player.Seek", "params": { "playerid": '$player_id', "value" : "smallbackward" }, "id": 1}'
}

function send_text {
    echo "Sending the text"
    xbmc_req '{"jsonrpc": "2.0", "method": "Input.SendText", "params": { "text": "'$1'" }}'
}

function move_down {
    xbmc_req '{"jsonrpc": "2.0", "method": "Input.Down"}'
}

function system_shutdown {
    xbmc_req '{"jsonrpc":"2.0","method":"System.Shutdown","id":1}'
}

function move_up {
    xbmc_req '{"jsonrpc": "2.0", "method": "Input.Up"}'
}

function move_left {
    xbmc_req '{"jsonrpc": "2.0", "method": "Input.Left"}'
}

function move_right {
    xbmc_req '{"jsonrpc": "2.0", "method": "Input.Right"}'
}

function input_info {
    xbmc_req '{"jsonrpc": "2.0", "method": "Input.Info"}'
}

function input_back {
    xbmc_req '{"jsonrpc": "2.0", "method": "Input.Back"}'
}

function input_ok {
    xbmc_req '{"jsonrpc": "2.0", "method": "Input.Select"}'
}

function system_reboot {
    xbmc_req '{"jsonrpc": "2.0", "method": "System.Reboot", "id": 1}'
}

function pipe_text {
    while IFS= read -r input; do
    xbmc_req '{"jsonrpc": "2.0", "method": "Input.SendText", "params": { "text": "'$input'" }}'
    done
}

function update_libraries {
    echo "Updating the video libraries"
    xbmc_req '{"jsonrpc": "2.0", "method": "VideoLibrary.Scan", "id": "mybash"}'
    echo "Updating the audio libraries"
    xbmc_req '{"jsonrpc": "2.0", "method": "AudioLibrary.Scan", "id": "mybash"}'

}

function clean_libraries {
    echo "Cleaning the libraries"
    xbmc_req '{"jsonrpc": "2.0", "method": "AudioLibrary.Clean", "id": "mybash"}'
    xbmc_req '{"jsonrpc": "2.0", "method": "VideoLibrary.Clean", "id": "mybash"}'
}


function press_key {

    ACTION=''
    CLR="\e[K"

    case "$1" in
        A) ACTION='Up'
            echo -ne "\rUp$CLR";
            ;;
        B) ACTION='Down'
            echo -ne "\rDown$CLR";
            ;;
        C) ACTION='Right'
            echo -ne "\rRight$CLR";
            ;;
        D) ACTION='Left'
            echo -ne "\rLeft$CLR";
            ;;
        c) ACTION='ContextMenu'
            echo -ne "\rContext Menu$CLR";
            ;;
        i) ACTION='Info'
            echo -ne "\rInformation$CLR";
            ;;
        $'\177') ACTION='Back'
            echo -ne "\rBack$CLR";
            ;;
        "") ACTION='Select'
            echo -ne "\rSelect$CLR";
            ;;
    esac

    if [[ "$ACTION" != " " ]] && [[ $LOCK == false  ]]
    then
        LOCK=true
        xbmc_req '{"jsonrpc": "2.0", "method": "Input.'$ACTION'"}'
        LOCK=false
    fi
}

function handle_keys {
    echo "Interactive navigation key: ";
    while :
    do
        read  -s -n1 key

        if [[ $key = q ]]
        then
            break
        elif [[ $key != ' ' ]]
        then
            press_key "$key"
        fi
    done
}

function volume_mute {
    echo "Volume mute"
    xbmc_req '{ "jsonrpc": "2.0", "method": "Application.SetMute", "params": { "mute": "toggle" }, "id": 1 }'
}
function volume_up {
    echo "Incrementing volume"
    xbmc_req '{ "jsonrpc": "2.0", "method": "Application.SetVolume", "params": { "volume": "increment" }, "id": 1 }'
}

function volume_down {
    echo "Decrementing volume on"
    xbmc_req '{ "jsonrpc": "2.0", "method": "Application.SetVolume", "params": { "volume": "decrement" }, "id": 1 }'
}

function handle_volume {
    echo "Press up/down for volume adjustment (q to quit): ";
    while :
    do
        read  -s -n1 key
        if [[ $key = q ]];then
            printf "\n"
            break
        elif [[ $key == 'A' ]]; then
            printf "\r+ Volume increasing."
            xbmc_req '{ "jsonrpc": "2.0", "method": "Application.SetVolume", "params": { "volume": "increment" }, "id": 1 }'
        elif [[ $key == 'B' ]];then
            printf "\r- Volume decreasing."
            xbmc_req '{ "jsonrpc": "2.0", "method": "Application.SetVolume", "params": { "volume": "decrement" }, "id": 1 }'
        fi
    done
}

function fullscreen_toggle {
    # Get Active players first
    output=`xbmc_req '{"jsonrpc": "2.0", "method": "Player.GetActivePlayers", "id": 99}' true`
    player_id=`echo $output | parse_json "playerid"`
    echo "Toggle fullscreen on the player with ID => $player_id"
    xbmc_req '{ "jsonrpc": "2.0", "method": "GUI.SetFullscreen", "params": { "fullscreen": "toggle" }, "id": 1 }'
}

function show_help {

echo -e "\n kodi-cli -[p|i|h|s|y youtube URL/ID|t 'text to send']\n\n" \
    "-p Play/Pause the current played video\n" \
    "-s Stop the current played video\n" \
    "-j Skip forward in the current played video\n" \
    "-k Skip backward in the current played video\n" \
    "-y Play youtube video. Use either URL/ID (of video)\n" \
    "-q Queue youtube video to the current list. Use either URL/ID (of video). Use instead of -y.\n" \
    "-o Play youtube video directly on Kodi. Use the name of video.\n" \
    "-v Interactive volume control\n" \
    "-i Interactive navigation mode. Accept keyboard keys of Up, Down, Left, Right, Back,\n" \
    "   Context menu and information\n" \
    "-l Play default playlist (most useful after using -q a few times)\n" \
    "-t 'text to send'\n" \
    "-r Send text from stdin to kodi\n" \
    "-u Increment the volume on Kodi\n" \
    "-d Decrement the volume on Kodi\n" \
    "-x Mute/Unmute the volume on Kodi\n" \
    "-f Toggle fullscreen\n" \
    "-m Update libraries\n" \
    "-n Clean libraries\n" \
    "-h Showing this help message\n"

}

## main
## check Bash version compatibility
if ((BASH_VERSINFO[0] < 4)); then
    echo -e "Error: $0 requires Bash version 4+"
    exit 1
fi
## check if we have any argument
if [ $# -eq 0 ];then
    echo -e "\n failure: make sure there is at least one argument"
    show_help
    exit
fi

## ---- Configuration --- ##
## Configure your KODI RPC details here
KODI_HOST=192.168.1.247
KODI_PORT=8080
KODI_USER=
KODI_PASS=
LOCK=false

# If the script does not have configuration hardcoded, the script will
# search for it in $HOME/.kodirc

function hex2string () {
  I=0
  while [ $I -lt ${#1} ];
  do
    get_str=$get_str`echo -en "\x"${1:$I:2}`
    let "I += 2"
  done
}
hex2string "$3"
if [[ $get_str == "-u" ]]; then
    volume_up;
    elif [[ $get_str == "-d" ]]; then
    volume_down;
    elif [[ $get_str == "-down" ]]; then
    move_down;
    elif [[ $get_str == "-up" ]]; then
    move_up;
    elif [[ $get_str == "-right" ]]; then
    move_right;
    elif [[ $get_str == "-left" ]]; then
    move_left;
    elif [[ $get_str == "-info" ]]; then
    input_info;
    elif [[ $get_str == "-back" ]]; then
    input_back;
    elif [[ $get_str == "-ok" ]]; then
    input_ok;
    elif [[ $get_str == "-reboot" ]]; then
    system_reboot;
    elif [[ $get_str == "-shutdown" ]]; then
    system_shutdown;
fi

if [ -z "$KODI_HOST" ]; then
    if [ -f "$HOME/.kodirc" ];then
        readarray -t line < "$HOME/.kodirc"
        KODI_HOST=${line[0]}
        KODI_PORT=${line[1]}
        KODI_USER=${line[2]}
        KODI_PASS=${line[3]}
    KODI_PASSWORD_COMMAND=${line[4]}
    fi
fi

# Ensure some configuration is loaded, or exit.
if [ -z "$KODI_HOST" ]; then
    echo -e "\n failure: Some Kodi configurations are not loaded. Please make sure they are."
    show_help
    exit
fi

#Run an external command to fetch the password if neccessary.
if [ -z "$KODI_PASS" ] && [ -n "$KODI_PASSWORD_COMMAND" ]; then
    KODI_PASS=$($KODI_PASSWORD_COMMAND)
fi

## Process command line arguments
while getopts "yqoprstiudfhvmnjklx" opt; do
    case $opt in
        l)  #play default playlist
            play_playlist
            ;;
        y)
            #play youtube video
            play_youtube $2
            ;;
        q)
            #queue youtube video
            queue_yt_videos $2
            ;;
        o)
            #play youtube video directly
            #this depends on using mps-youtube
            play_youtube `mpsyt /$2, i 1, q | grep -i link | awk -F 'v=' '{ print $2 }'`
            ;;
        p)
            play_pause
            ;;
        s)
            stop
            ;;
    r)
        pipe_text
        ;;

        t)
            send_text $2
            handle_keys
            ;;
        i)
            handle_keys
            ;;
        u)
            volume_up
            ;;
        d)
            volume_down
            ;;
        f)
            fullscreen_toggle
            ;;
        h)
            show_help
            ;;
        m)
            update_libraries
            ;;
        n)
            clean_libraries
            ;;
        v)
            handle_volume
            ;;
        j)
            skip_forward
            ;;
        k)
            skip_backward
            ;;
        x)
            volume_mute
            ;;

    esac
done
