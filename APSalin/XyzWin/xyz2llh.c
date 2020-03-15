/* @(#)xyz2llh.c        1.5  02/02/07 */
static char *sccsid= "@(#)xyz2llh.c     1.5  02/02/07";

/********1*********2*********3*********4*********5*********6*********7*********
 * name:            xyz2llh
 * version:         9901.28
 * written by:      M. Schenewerk
 * purpose:         converts elliptic lat, lon, hgt <-> X, Y, Z
 *
 * input parameters
 * -----------------------------
 *
 * output parameters
 * -----------------------------
 *
 *
 * local variables and constants
 * -----------------------------
 * c                command-line option
 * display          = 1 = display latitude and longitude in deg min sec
 *                        rather than decimal degrees
 * errflg           command-line error/usage print flag
 * i                loop counter
 * in[]             input coordinates
 * j                loop counter
 * mode             display mode
 *                  = 0 = X, Y, Z -> lat, lon, hgt
 *                  = 1 = lat, lon, hgt -> X, Y, Z
 * out[]            output coordinates
 * pgm              program name
 * ptr              scratch string pointer
 * vrsn             program version ID
 * west             = 1 = longitudes are west rather than east longitude
 *
 * global variables and constants
 * ------------------------------
 * eflat            Earth flattening factor
 * emajor           Earth's semi-major axis [m]
 * optarg           argument of an option flag
 * optind           parameter count of first argument after all flags
 * optopt           argument triggering an error in getopt
 *
 *
 * calls:
 * -----------------------------
 * plh2xyz          lat, lon, hgt to X, Y, Z
 * xyz2plh          X, Y, Z to lat, lon, hgt
 *
 * include files:
 * -----------------------------
 * physcon.h        general physical constants
 * libgpsC.h        library definitions and prototype statements
 *
 * references:
 * -----------------------------
 * McCarthy (ed), IERS Technical Note 13,
 *   July 1992, Observatoire de Paris.
 *
 * comments:
 * -----------------------------
 *
 * see also:
 * -----------------------------
 *
 ********1*********2*********3*********4*********5*********6*********7*********
 *:modification history
 *:9406.16, MSS, Convert from FORTRAN program wgs84.
 *:9901.21, MSS, Rewrite of xyz program.
 *:9901.28, MSS, Improve trap for negative coordinates.
 ********1*********2*********3*********4*********5*********6*********7********/

/*
 *  include files
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "physcon.h"
#include "libgpsC.h"

/*
 *  function prototypes
 */


/*
 *  global definitions and variables
 */



int main( int argc, char *argv[] )
{
  char buf[81];
  char *pgm;
  char *ptr;
  char *vrsn= "1.5 02/02/07";
  double in[3]= { 0.0, 0.0, 0.0 };
  double out[3];
  double sec;
  int c;
  int deg;
  int display= 0;
  int errflg= 0;
  int i;
  int j;
  int min;
  int mode= 0;
  int west= 0;

  extern char *optarg;
  extern int optind;
  extern int optopt;

/*
 *   1.0  Parse command line
 */

  pgm= argv[0];
  while( (ptr= strpbrk( pgm, "/\\:" )) != NULL )
    pgm= ptr+1;

  i= 0;
  while( (c= getopt(argc, argv, ":dhrw0:1:2:3:4:5:6:7:8:9:")) != -1 )
    switch( c ) {
    case 'd':
      display= 1;
      break;
    case 'h':
      errflg= 1;
      break;
    case 'r':
      mode= 1;
      break;
    case 'w':
      west= 1;
      break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      sprintf( buf, "-%c%s", optopt, optarg );
      in[i]= atof( buf );
      i++;
      break;
    case '?':
      fprintf(stderr, "%s ERROR: Unrecognized option \"%c\"\n",
         pgm, optopt);
      errflg++;
      break;
    case ':':
      errflg++;
      break;
    }

  if( errflg
      || ( mode == 0 && (argc-optind+i) != 3 )
      || ( mode == 1 && (argc-optind+i) != 2 && (argc-optind+i) != 3 ) ) {
    printf("%s(%s): Converts X Y Z to lat, lon and ellipsoid hgt\n",
           pgm, vrsn);
    printf("Usage: %s X Y Z\n", pgm );
    printf("  options:\n");
    printf("           -d print deg min sec rather than decimal degrees.\n");
    printf("           -h prints this message.\n");
    printf("           -r = input coordinates are lat, lon, hgt,\n");
    printf("                output coordinates will be X, Y, Z.\n");
    printf("           -w longitudes are west rather than east longitude.\n");
    exit(1);
  }

/*
 *   1.1  Convert and store input coordinates
 *        NOTE: i initialized above getopt loop.
 */

  for( ; optind < argc; optind++, i++ )
    in[i]= atof(argv[optind]);

/*
 *   2.0  Convert and print coordinates
 */

  if( mode == 1 ) {
    if( west == 1 )
      in[1]= fmod( 360.0-in[1], 360.0 );

    plh2xyz( in, out, emajor, eflat );

    printf( "%13.4lf %13.4lf %13.4lf\n", out[0], out[1], out[2] );
  } else {
    xyz2plh( in, out, emajor, eflat );

    if( west == 1 )
      out[1]= fmod( 360.0-out[1], 360.0 );

    if( display == 1 ) {
      degdms( out[0], &deg, &min, &sec );
      printf( "%3d %2d %8.5lf", deg, min, sec );

      degdms( out[1], &deg, &min, &sec );
      printf( " %3d %2d %8.5lf", deg, min, sec );

      printf( " %13.8lf\n", out[2] );
    } else
      printf( "%16.10f %16.10lf %13.5lf\n", out[0], out[1], out[2] );
  }

  exit(0);
}
