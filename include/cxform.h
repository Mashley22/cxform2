/*
** cxform.h  --  prototypes and headers for Ed's coordinate transform package
*/

#ifndef CXFORM_H
#define CXFORM_H

enum systems { UNKNOWN, J2000, GEI, GEO, MAG, GSE, GSM, SM, RTN, GSEQ, HEE, HAE, HEEQ };

typedef double Vec[3];
typedef double Mat[3][3];


/**
 *@brief the main cxform functions
 *
 *@param[in] from/from_n the input coordinate system, either a \ref system or a string,
 *                       the string should be the same as one of the systems, in either case
 *
 *@param[in] to/to_n same as the from parameter but for the ouput coordinate system
 *
 *@param[in] t the time, should be in epherimis seconds past J2000, see \ref date2es
 *
 *@param[in] v_in the input coordinate, in the input coordinate system
 *
 *@param[out] v_out the ouput coordinate, in the output coordinate system
 *
 */
int cxform(const char *from,const char *to,const double t,const Vec v_in,Vec v_out);
int cxform2(const enum systems from_n, const enum systems to_n,const double t,const Vec v_in,Vec v_out);

char *cxform_err(void);

/*
** Utility functions
*/
double gregorian_calendar_to_jd(int y, int m, int d, int h, int mi, int s);
long cxRound(double doub);
long date2es(int yyyy, int mm, int dd, int hh, int mm2, int ss);

/*
** Matrix multiplication and transposition
*/
void mat_transpose(Mat m_in, Mat m_out);
void mat_times_mat(Mat m1,   Mat m2, Mat m_out);
void mat_times_vec(Mat m1,   const Vec v1, Vec v_out);

enum direction { FORWARD, BACK };
typedef enum direction Direction;


#endif
