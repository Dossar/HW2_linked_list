/* 
 * File:   LinkedLists.h
 * Author: mike
 *
 * Created on September 16, 2013, 10:38 PM
 */


#ifndef LINKEDLISTS_H
#define	LINKEDLISTS_H

#ifdef	__cplusplus
extern "C" {
#endif

   void l_check(int position);
   void l_insert(int data);
   void l_remove(void);
   void l_display(void);
   //void l_display(int start);
   void l_remove_big_elements();

#ifdef	__cplusplus
}
#endif

#endif	/* LINKEDLISTS_H */

