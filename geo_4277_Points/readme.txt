***** The following files are included :
************************************************
	fi_lam_h(4277).txt
	rZ.txt
	XYZ.txt
************************************************
- All files have header in the first line
- All units are in meter
- All angles are in decimal degree
************************************************
fi_lam_h(4277).txt
*******************
Original input file, created manually.
Header: latitude angle (fi), longitude angle (lamda), height (h) 
all points are 4277 points. where 3185 with positive height and 1092 with negative heights.

	Angle (φ): (0.001° ≤φ ≤89.999°),φ ∈{0.001,1,2,3,…,87,88,89,89.999}.
	Angle (λ = 45°). The longitude is constant.
	Height (h): (-1000000 m ≤h ≤1000000000 m).
	Sample size = Count of (φ) * Count of (h) = 91×47=4277 points.


ID	height(m)	ID	height (m)	ID	height(m)	ID	height(m)	ID height(m)
1	100	        11	750000	    21	20000000	31	350000000	41	-100000
2	500	        12	1000000	    22	25000000	32	400000000	42	-200000
3	1000	    13	2500000	    23	30000000	33	500000000	43	-300000
4	10000	    14	5000000	    24	35000000	34	750000000	44	-400000
5	50000	    15	6000000	    25	40000000	35	1000000	    45	-500000
6	100000	    16	7000000	    26	50000000	36	-100	    46	-750000
7	200000	    17	8000000	    27	75000000	37	-500	    47	-1000000
8	300000	    18	9000000	    28	100000000	38	-1000		
9	400000	    19	10000000	29	200000000	39	-10000		
10	500000	    20	15000000	30	300000000	40	-50000		

************************************************
XYZ.txt
*******************
Created by program, it is the Cartesian coordinates (X,Y,Z) of (φ,λ,h)
Header: X,Y,Z
************************************************
rZ.txt
*******************
Created by program, it is the Cartesian coordinates (r,Z) of (φ,λ,h)
Header: r,Z
r = SQRT(X*X + Y*Y)
