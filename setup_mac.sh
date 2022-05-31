#!/bin/bash
# Copyright 2022 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# This script installs the packages required for a MacOS host
# to build apps for and flash the Coral Dev Board Micro

set -ex

brew install \
  protobuf \
  cmake \
  libusb \
  lsusb

python3 -m pip install pip --upgrade
python3 -m pip install -r scripts/requirements.txt