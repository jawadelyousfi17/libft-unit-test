SCRIPT_DIR="$(cd "$(dirname "$0")"; pwd)"
NODE_SCRIPT="$SCRIPT_DIR/app/run.js"
node "$NODE_SCRIPT" "$@"
