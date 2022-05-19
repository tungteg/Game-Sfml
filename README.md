I, **Hướng dẫn cài đặt thư viện SFML TRÊN DEV C++**
 b1. Mở dev c++, trên thanh công cụ chọn Project -> chọn Project Options
 b2. Chọn Parameters, trong Linker chúng ta dán 4 dòng sau vào:
  -lsfml-audio
  -lsfml-graphics
  -lsfml-window
  -lsfml-system 
 b3. Chọn Directories, trong Libary Directories chúng ta add đường dẫn: SFML-2.4.2\lib
                       trong Include Directories ta add đường dẫn: SFML-2.4.2\include
 b4. chọn OK, thế là xong các bước cài đặt thư viện sfml vào dev c++. Video hướng dẫn chi tiết (https://www.youtube.com/watch?v=uAd2jINKCxc).

