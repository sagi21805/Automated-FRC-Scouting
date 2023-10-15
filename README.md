# Installation


## Install cmake

`bash
 sudo apt install -y g++ cmake make git libgtk2.0-dev pkg-config 
`

## Intall Cuda -->
 https://gist.github.com/denguir/b21aa66ae7fb1089655dd9de8351a202


## Install OpenCV + Cuda
`bash
cd ~
`

`bash
 sudo apt install ffmpeg
`

`bash
 git clone https://github.com/opencv/opencv_contrib.git
`

`bash
 git clone https://github.com/opencv/opencv.git
`

`bash
 pip install virtualenv
 python3 -m venv ~/env
 source env/bin/activate
 pip install numpy
`

`bash
 cd opencv
`

`bash
 mkdir -p build && cd build
`

`bash
 cmake -B ./build \
      -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D INSTALL_PYTHON_EXAMPLES=OFF \
      -D INSTALL_C_EXAMPLES=OFF \
      -D OPENCV_ENABLE_NONFREE=ON \      
      -D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules \
      -D PYTHON_EXECUTABLE=~/env/bin/python3 \
      -D BUILD_EXAMPLES=ON \
      -D WITH_CUDA=ON \
      -D WITH_CUDNN=ON \
      -D OPENCV_DNN_CUDA=ON \
      -D WITH_CUBLAS=ON \       
      -D CUDA_TOOLKIT_ROOT_DIR= /path/to/cudafolder \
      -D OpenCL_LIBRARY= /path/to/libOpenCL.so
`

`bash
 make -j4
`

`bash
 sudo make install 
 sudo ldconfig
`

`bash
cd ~/env/lib/python3.x/site-packages/
ln -s /usr/local/lib/python3.x/site-packages/cv2/python-3.x/cv2.cpython-3xm-x86_64-linux-gnu.so cv2.so
`

## Install cnpy

`bash
 cd ~
`

`bash
 git clone https://github.com/rogersce/cnpy.git
`

`bash
 cd mkdir -p build && cd build
`

`bash
 cmake ../cnpy
`

`bash
 make -j4
`

`bash
 sudo make install 
`

# install python modules
`bash
 pip install -r requirements.txt
`
