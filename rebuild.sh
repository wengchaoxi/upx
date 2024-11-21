docker run --rm --user root -v ./:/home/upx/src/upx docker.io/wengchaoxi/upx-stubtools:latest bash -c $'
set -ex; set -o pipefail
cd /home/upx/src/upx

# # check whitespace
# [[ -d .git ]] && bash ./misc/scripts/check_whitespace_git.sh

# rebuild docs
make -C doc clean all

# rebuild stubs
cd /home/upx/src/upx/src/stub
export PATH=$PATH:/usr/local/bin/bin-upx-20221212/
make maintainer-clean extra-clean
git status . || true # make sure the stub files got deleted
make extra-all all
echo "===== Rebuilt stubs. All done. ====="
exit 0
'
make all

