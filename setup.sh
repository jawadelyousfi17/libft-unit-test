#!/bin/bash

# Determine which shell is being used
if [[ "$SHELL" == *"bash"* ]]; then
    echo "Using bash"
    # Add alias to .bashrc
    echo "alias badt='~/libft-unit-test/run_test.sh'" >> ~/.bashrc
    # Reload .bashrc
    #show message
    source ~/.bashrc
elif [[ "$SHELL" == *"zsh"* ]]; then
    echo "Using zsh "
    # Add alias to .zshrc
    echo "alias badt='~/libft-unit-test/run_test.sh'" >> ~/.zshrc
    # Reload .zshrc
    echo "Setup ended"
    zsh -c "source ~/.zshrc"
else
    echo "Unknown shell. Only bash and zsh are supported."
fi
