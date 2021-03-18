#!/bin/bash
required_id='MS306511*'
if ! grep -iqE "$required_id" "$1"; then
	echo "[git hook] Commit-msg format validation: FAILURE. [initials+student ID] required."
	exit 1;
fi
echo "[git hook] Commit-msg format validation: SUCCESS"
exit 0;