/*
 * Builtin header files.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_sf_fermi_dirac.h>

/*
 *  Order of inclusion of the user defined header files is very important.
 */
#include "../Global/global.h"
#include "../Structures/structures.h"
#include "../Subsidiary_Subroutines/factorial.h"
#include "../Subsidiary_Subroutines/shape_of_file.h"
#include "../Crs_sctn/cross_section.h"
#include "../Rates/rates.h"
#include "../Master/master.h"