#!/usr/bin/env bash

# Hard-code root directory here if desired, otherwise defaults to current directory
ROOTDIR="${ROOTDIR:-$(pwd)}"

linkfileswithconf() {
    absroot=$(realpath "$ROOTDIR")

    # Ensure linkfiles.conf exists in root
    if [[ ! -f "$absroot/linkfiles.conf" ]]; then
        echo "Error: linkfiles.conf not found in $absroot"
        return 1
    fi

    while IFS= read -r line; do
        [[ -z "$line" || "$line" != *:* ]] && continue

        IFS=: read -r parent symlink <<< "$line"

        abs_parent="$absroot/$parent"
        abs_symlink="$absroot/$symlink"

        if [[ -e "$abs_parent" ]]; then
            ln -sf "$abs_parent" "$abs_symlink"
            echo "Restored symlink: $abs_symlink -> $abs_parent"
        else
            echo "Warning: parent target missing ($abs_parent), skipped $abs_symlink"
        fi
    done < "$absroot/linkfiles.conf"

    echo "Finished restoring symlinks from linkfiles.conf"
}

linkfileswithconf

