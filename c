#!/bin/bash

# Load config file
config_file="$(dirname "$0")/config.sh"
if [ -f "$config_file" ]; then
  source "$config_file"
else
  echo "Error: Config file not found: $config_file"
  exit 1
fi

# Check configuration variables
if [ -z "$remote_host" ]; then
  echo "Error: Please set remote_host in config.sh file."
  exit 1
fi

if [ -z "$editor" ]; then
  echo "Error: Please set editor in config.sh file."
  exit 1
fi


if [ -z "$1" ]; thens
  target_dir="."
else
  target_dir="$1"
fi


if ! absolute_dir=$(cd "$target_dir" && pwd); then
  echo "Error: Cannot access '$target_dir'"
  exit 1
fi


remote_command="${editor} --remote ssh-remote+${remote_host} ${absolute_dir}"

# Copy to clipboard
printf "\033]52;c;%s\a" "$(printf "%s" "$remote_command" | base64)"

echo
echo "$remote_command"
echo -e "\e[1;32mCopied to Clipboard!\e[0m"
echo
