<h2>For running on a windows system:</h2>
To use the gmp library download the gmp files using https://www.msys2.org/ and use the command: "pacman -S mingw-w64-x86_64-gmp". The gmp files will now be in your mingw bundle, and in the cmake file set the absolute path to your mingw/include and mingw/lib folders on line 6 and 7. If using an editor like clion, make sure the toolchain is set up to the bundle with gmp files downloaded.

<h4>command line for running om windows:</h4>
__ g++ -std=c++17 -I/msys64/mingw64/include -L/msys64/mingw64/lib main.cpp src/PiApproximationAlgorithm.cpp src/MonteCarloApproximation.cpp src/MachinsFormulaPiApproximation.cpp src/GaussLegendreAlgorithm.cpp -lgmp -lgmpxx -o piApproximation __
<h3>For running on unix based system gmp.h will be available without any action.</h3>

<h3>Monte carlo algorithm:</h3>

![image](https://github.com/user-attachments/assets/c9b02bde-339f-42e2-9f47-209e31c25f9b)

<h3>Machins formula :</h3>

![image](https://github.com/user-attachments/assets/17842720-39b5-4188-ae9e-e0121cbe2cd7)

<h3>Eulers arctan approximation used in machins formula:</h3>
![image](https://github.com/user-attachments/assets/4f7bbaca-7a23-4530-9509-b84cbed4b3a3)

<h3>Gauss Legendre algorithm</h3>
![image](https://github.com/user-attachments/assets/0eb9a28c-1e00-4d10-9ded-4ba16dcc4f5b)
<h4>Square root approximation used for Gauss Legendre</h4>
![image](https://github.com/user-attachments/assets/31b1d3de-7f52-4011-94b9-ca4b1f2e6d39)

