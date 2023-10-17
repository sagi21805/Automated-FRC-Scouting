# Installation

## Install cmake

`
sudo apt install -y g++ cmake make git libgtk2.0-dev pkg-config 
`

## Install OpenCV
`
cd ~
`

`
git clone https://github.com/rogersce/cnpy.git
`
sudo apt install ffmpeg
sudo apt install pkg-config     
sudo apt install ffmpeg libavformat-dev libavcodec-dev libswscale-dev 


`
cd mkdir -p build && cd build
`

`
cmake ../cnpy
`

`
make -j4
`

`
sudo make install 
`

## Install cnpy

`
cd ~
`

`
git clone https://github.com/rogersce/cnpy.git
`

`
cd mkdir -p build && cd build
`

`
cmake ../cnpy
`

`
make -j4
`

`
sudo make install 
`

# for python modules
`
pip install -r requirements.txt
`
