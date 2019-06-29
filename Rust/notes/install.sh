#!/bin/sh

# download rustup
curl https://sh.rustup.rs -sSf | sh

# automatically addsd Rust to system PATH after next login
# run folowing to do so right away
# source $HOME/.cargo/env

# Need C linker. Some common Rust packages depend on C code and will need a C compiler


