# An FPGA Accelerator for Image Classification with Convolutional Neural Networks.

![Devanagari Digits](Solution/images/devanagari-digits.png?raw=true "Devanagari Digits")

The model was pre-trained on tensorflow with accuracy 98.93 % on test dataset. After obtaining trained weights and biases, corresponding functions were written in C++ for translation into hardware description languages. It takes roughly 7 million cycles to run the C++ executable directly on CPU. We were finally able to reduce our latency to 0.33 million on FPGA implementation. We use arbitrary precision numbers instead of floating point numbers (ap_fixed<9,1> for fractions, ap_fixed<12,5> for others) without compromising much on accuracy.


**Objective**: Given an input devanagari handwritten digit image, output an array of probabilities of being a particular digit.

**Model**:
(Input) ============================================================== [32x32x1]  
(Convolution with [5x5] filter with 7 channels + ReLu activation) ==== [28x28x7]  
(Max Pooling with [4x4] pool window) ================================= [7x7x7]  
(Flatten to dense layer + ReLu activation) =========================== [64]  
(Output with Softmax activation) ===================================== [10]  



## Performance on CPU
![CPU stats](Solution/images/perf-stats.png?raw=true "CPU stats")

<html>
<body>
  <center>
    <h1>Synthesis Report for 'dev_digits_classify'</h1>
  </center>
  <h2 style="background-color:#f7f7ff;">General Information</h2> <b style="padding-left:20px;">Date: </b> Wed May 15 22:09:41 2019
  <br> <b style="padding-left:20px;">Version: </b> 2018.2 (Build 2258646 on Thu Jun 14 20:25:20 MDT 2018)<br> <b style="padding-left:20px;">Project: </b> dev_fused<br> <b style="padding-left:20px;">Solution: </b> solution4<br> <b
    style="padding-left:20px;">Product family: </b> zynq<br> <b style="padding-left:20px;">Target device: </b> xc7z020clg484-1<br>
  <h2 style="background-color:#f7f7ff;">Performance Estimates</h2>
  <ul>
    <li><b>Timing (ns)</b><br><br>
      <ul>
        <li><b>Summary</b><br><br>
          <ul>
            <table border="1" " cellspacing=" 0">
            <tr>
            <th align="center" style="background-color:#CCECFF;">Clock</th>
            <th align="center" style="background-color:#CCECFF;"> Target</th>
            <th align="center" style="background-color:#CCECFF;"> Estimated</th>
            <th align="center" style="background-color:#CCECFF;"> Uncertainty</th>
            </tr>
              <tr>
                <td align="left" style="background-color:#CCECFF;">ap_clk</td>
                <td align="right" style="background-color:#CCECFF;">10.00</td>
                <td align="right" style="background-color:#CCECFF;">8.677</td>
                <td align="right" style="background-color:#CCECFF;">1.25</td>
              </tr>
            </table>
          </ul>
        </li>
      </ul>
    </li>
  </ul>

  <ul>
    <li><b>Latency (clock cycles)</b><br><br>
      <ul>
        <li><b>Summary</b><br><br>
          <ul>
            <table border="1" " cellspacing=" 0">
              <tr>
                <th align="center" colspan="2" style="background-color:#CCECFF;">Latency</th>
                <th align="center" colspan="2" style="background-color:#CCECFF;">Interval</th>
                <th align="center" rowspan="2" style="background-color:#CCECFF;"> Type</th>
              </tr>
              <tr>
                <th align="center" style="background-color:#CCECFF;"> min</th>
                <th align="center" style="background-color:#CCECFF;"> max</th>
                <th align="center" style="background-color:#CCECFF;"> min</th>
                <th align="center" style="background-color:#CCECFF;"> max</th>
              </tr>
              <tr>
                <td align="right" style="background-color:#CCECFF;">323925</td>
                <td align="right" style="background-color:#CCECFF;">351365</td>
                <td align="right" style="background-color:#CCECFF;">323925</td>
                <td align="right" style="background-color:#CCECFF;">351365</td>
                <td align="right" style="background-color:#CCECFF;">none</td>
              </tr>
            </table>
          </ul>
        </li>
        <li><b>Detail</b><br><br>
          <ul>
            <li><b>Instance</b><br><br>
              <ul>
                <table border="1" " cellspacing=" 0">
                  <tr>
                    <th align="center" rowspan="2" style="background-color:#CCECFF;">Instance</th>
                    <th align="center" rowspan="2" style="background-color:#CCECFF;"> Module</th>
                    <th align="center" colspan="2" style="background-color:#CCECFF;">Latency</th>
                    <th align="center" colspan="2" style="background-color:#CCECFF;">Interval</th>
                    <th align="center" rowspan="2" style="background-color:#CCECFF;"> Type</th>
                  </tr>
                  <tr>
                    <th align="center" style="background-color:#CCECFF;"> min</th>
                    <th align="center" style="background-color:#CCECFF;"> max</th>
                    <th align="center" style="background-color:#CCECFF;"> min</th>
                    <th align="center" style="background-color:#CCECFF;"> max</th>
                  </tr>
                  <tr>
                    <td align="left" style="background-color:#CCECFF;">grp_convolve_fu_387</td>
                    <td align="left" style="background-color:#CCECFF;">convolve</td>
                    <td align="right" style="background-color:#CCECFF;">208958</td>
                    <td align="right" style="background-color:#CCECFF;">236398</td>
                    <td align="right" style="background-color:#CCECFF;">208958</td>
                    <td align="right" style="background-color:#CCECFF;">236398</td>
                    <td align="right" style="background-color:#CCECFF;">none</td>
                  </tr>
                  <tr>
                    <td align="left" style="background-color:#CCECFF;">grp_densifyto64_fu_399</td>
                    <td align="left" style="background-color:#CCECFF;">densifyto64</td>
                    <td align="right" style="background-color:#CCECFF;">111048</td>
                    <td align="right" style="background-color:#CCECFF;">111048</td>
                    <td align="right" style="background-color:#CCECFF;">111048</td>
                    <td align="right" style="background-color:#CCECFF;">111048</td>
                    <td align="right" style="background-color:#CCECFF;">none</td>
                  </tr>
                </table>
              </ul>
            </li>
            <li><b>Loop</b><br><br>
              <ul>
                <table border="1" " cellspacing=" 0">
                  <tr>
                    <th align="center" rowspan="2" style="background-color:#CCECFF;">Loop Name</th>
                    <th align="center" colspan="2" style="background-color:#CCECFF;">Latency</th>
                    <th align="center" rowspan="2" style="background-color:#CCECFF;">Iteration Latency</th>
                    <th align="center" colspan="2" style="background-color:#CCECFF;">Initiation Interval</th>
                    <th align="center" rowspan="2" style="background-color:#CCECFF;">Trip Count</th>
                  </tr>
                  <tr>
                    <th align="center" style="background-color:#CCECFF;"> min</th>
                    <th align="center" style="background-color:#CCECFF;"> max</th>
                    <th align="center" style="background-color:#CCECFF;"> achieved</th>
                    <th align="center" style="background-color:#CCECFF;"> target</th>
                  </tr>
                  <tr>
                    <td align="left" style="background-color:#CCECFF;">- Loop 1</td>
                    <td align="right" style="background-color:#CCECFF;">20</td>
                    <td align="right" style="background-color:#CCECFF;">20</td>
                    <td align="right" style="background-color:#CCECFF;">2</td>
                    <td align="center" style="background-color:#CCECFF;">-</td>
                    <td align="center" style="background-color:#CCECFF;">-</td>
                    <td align="right" style="background-color:#CCECFF;">10</td>
                  </tr>
                  <tr>
                    <td align="left" style="background-color:#CCECFF;">- Loop 2</td>
                    <td align="right" style="background-color:#CCECFF;">3392</td>
                    <td align="right" style="background-color:#CCECFF;">3392</td>
                    <td align="right" style="background-color:#CCECFF;">53</td>
                    <td align="center" style="background-color:#CCECFF;">-</td>
                    <td align="center" style="background-color:#CCECFF;">-</td>
                    <td align="right" style="background-color:#CCECFF;">64</td>
                  </tr>
                  <tr>
                    <td align="left" style="background-color:#CCECFF;"> + Loop 2.1</td>
                    <td align="right" style="background-color:#CCECFF;">50</td>
                    <td align="right" style="background-color:#CCECFF;">50</td>
                    <td align="right" style="background-color:#CCECFF;">5</td>
                    <td align="center" style="background-color:#CCECFF;">-</td>
                    <td align="center" style="background-color:#CCECFF;">-</td>
                    <td align="right" style="background-color:#CCECFF;">10</td>
                  </tr>
                  <tr>
                    <td align="left" style="background-color:#CCECFF;">- Loop 3</td>
                    <td align="right" style="background-color:#CCECFF;">250</td>
                    <td align="right" style="background-color:#CCECFF;">250</td>
                    <td align="right" style="background-color:#CCECFF;">25</td>
                    <td align="center" style="background-color:#CCECFF;">-</td>
                    <td align="center" style="background-color:#CCECFF;">-</td>
                    <td align="right" style="background-color:#CCECFF;">10</td>
                  </tr>
                  <tr>
                    <td align="left" style="background-color:#CCECFF;">- Loop 4</td>
                    <td align="right" style="background-color:#CCECFF;">250</td>
                    <td align="right" style="background-color:#CCECFF;">250</td>
                    <td align="right" style="background-color:#CCECFF;">25</td>
                    <td align="center" style="background-color:#CCECFF;">-</td>
                    <td align="center" style="background-color:#CCECFF;">-</td>
                    <td align="right" style="background-color:#CCECFF;">10</td>\
                  </tr>
                </table>
              </ul>
            </li>
          </ul>
        </li>
      </ul>
    </li>
  </ul>
  <h2 style="background-color:#f7f7ff;">Utilization Estimates</h2>
  <ul>
  <li><b>Summary</b><br><br>
    <ul>
      <table border="1" " cellspacing=" 0">
      <tr>
        <th align="center" style="background-color:#CCECFF;">Name</th>
        <th align="center" style="background-color:#CCECFF;"> BRAM_18K</th>
        <th align="center" style="background-color:#CCECFF;"> DSP48E</th>
        <th align="center" style="background-color:#CCECFF;"> FF</th>
        <th align="center" style="background-color:#CCECFF;"> LUT</th>
      </tr>
        <tr>
          <td align="left" style="background-color:#CCECFF;">DSP</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
          <td align="right" style="background-color:#CCECFF;">1</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
        </tr>
        <tr>
          <td align="left" style="background-color:#CCECFF;">Expression</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
          <td align="right" style="background-color:#CCECFF;">40</td>
          <td align="right" style="background-color:#CCECFF;">2325</td>
        </tr>
        <tr>
          <td align="left" style="background-color:#CCECFF;">FIFO</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
        </tr>
        <tr>
          <td align="left" style="background-color:#CCECFF;">Instance</td>
          <td align="right" style="background-color:#CCECFF;">23</td>
          <td align="right" style="background-color:#CCECFF;">9</td>
          <td align="right" style="background-color:#CCECFF;">1751</td>
          <td align="right" style="background-color:#CCECFF;">4030</td>
        </tr>
        <tr>
          <td align="left" style="background-color:#CCECFF;">Memory</td>
          <td align="right" style="background-color:#CCECFF;">2</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
          <td align="right" style="background-color:#CCECFF;">55</td>
          <td align="right" style="background-color:#CCECFF;">16</td>
        </tr>
        <tr>
          <td align="left" style="background-color:#CCECFF;">Multiplexer</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
          <td align="right" style="background-color:#CCECFF;">464</td>
        </tr>
        <tr>
          <td align="left" style="background-color:#CCECFF;">Register</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
          <td align="right" style="background-color:#CCECFF;">829</td>
          <td align="center" style="background-color:#CCECFF;">-</td>
        </tr>
        <tr>
          <td align="left" style="background-color:#CCECFF;">Total</td>
          <td align="right" style="background-color:#CCECFF;">25</td>
          <td align="right" style="background-color:#CCECFF;">10</td>
          <td align="right" style="background-color:#CCECFF;">2675</td>
          <td align="right" style="background-color:#CCECFF;">6835</td>
        </tr>
        <tr>
          <td align="left" style="background-color:#CCECFF;">Available</td>
          <td align="right" style="background-color:#CCECFF;">280</td>
          <td align="right" style="background-color:#CCECFF;">220</td>
          <td align="right" style="background-color:#CCECFF;">106400</td>
          <td align="right" style="background-color:#CCECFF;">53200</td>
        </tr>
        <tr>
          <td align="left" style="background-color:#CCECFF;">Utilization (%)</td>
          <td align="right" style="background-color:#CCECFF;">8</td>
          <td align="right" style="background-color:#CCECFF;">4</td>
          <td align="right" style="background-color:#CCECFF;">2</td>
          <td align="right" style="background-color:#CCECFF;">12</td>
        </tr>
      </table>
    </ul>
  </li>
</ul>

</body>

</html>

Our network is very small and uses just about 7% of total harware on board. Though, only two DSP units are being used effectively, other seven DSP units could have been easily avoided in last layer (the exponential softmax activation layer which uses floating point numbers by default.) by writing our own custom simpler function for casting to probabilities using ap_fixed numbers. {This occurred to me after our final project review :-(}



------------------------------------------------------------------
Dataset: Devanagari Handwritten Character Dataset Data Set (http://archive.ics.uci.edu/ml/datasets/Devanagari+Handwritten+Character+Dataset)
