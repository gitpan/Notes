/*
 * This file was generated automatically by xsubpp version 1.9508 from the 
 * contents of Session.xs. Do not edit this file, edit Session.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "Session.xs"
#define BLOCK Perl_BLOCK

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "notessession.h"


#line 20 "Session.c"
XS(XS_Notes__Session_new)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Notes::Session::new(CLASS)");
    SP -= items;
    {
	char *	CLASS = (char *)SvPV(ST(0),PL_na);
#line 17 "Session.xs"
      int    ln_stat_save;
      char * ln_warning;
      int    ln_rc;
      d_LN_XSVARS;
#line 34 "Session.c"
#line 22 "Session.xs"
      LN_PUSH_NEW_OBJ(CLASS, &PL_sv_undef);
      ln_global_session_count += 1;      /* NOT threadsafe ! */
      LN_SET_NVX(ln_obj, 0);
      LN_SET_OK(ln_obj);

      if(ln_global_session_count > 1)
      {
      	XSRETURN(1);
      }
      else if(ln_global_session_count == 1)
      {
		ln_rc = session_new();
      	LN_SET_IVX(ln_obj, (IV)ln_rc);
      }

      if(LN_IS_OK(ln_obj) && ln_global_session_count > 0)
      {
      	XSRETURN(1);
      }

      /* If we get here, we encountered errors; so handle them */
      /* Undo things from above for new session object s 	   */

	   ln_stat_save             = LN_IVX( ln_obj );
	   ln_global_session_count -= 1; /* NOT threadsafe !       */
	   POPs;                         /* pop new (invalid) object
	   							        ln_obj from stack      */

	   Newz(1, ln_warning, LN_WARNING_LENGTH_NO_NEW_SESSION, char);
	   if(ln_warning == (char *) NULL)
	   {
		   DEBUG(("Notes::Session object returning memory error (Newz()) at line %d", ln_rc, __LINE__));
		   XSRETURN_NOT_OK;
	   }

	   {  /* try to emit some warning for the errors from above;     */
	      /* a new C-block, because we had C-syntax probs thru dSP;  */
		   dSP;
	       ENTER;
	       SAVETMPS;
	       PUSHMARK(sp);
	       sprintf(ln_warning, "%s 0x%08X/0x%08X",
	           LN_WARNING_NO_NEW_SESSION,
	           ln_stat_save,
	           ln_global_session_count           /* NOT threadsafe!  */
	       );
	       XPUSHs( sv_2mortal( newSVpv(
	          ln_warning, strlen( ln_warning )
	       )));
	       PUTBACK;
	       perl_call_pv( "Carp::carp", G_DISCARD );
	       SPAGAIN;
	       PUTBACK;           /* was G_DISCARD, so nothing to pop off */
	       FREETMPS;
	       LEAVE;
	       Safefree( ln_warning );
	   }
	   XSRETURN_NOT_OK;
#line 94 "Session.c"
	PUTBACK;
	return;
    }
}

XS(XS_Notes__Session_DESTROY)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Notes::Session::DESTROY(s)");
    SP -= items;
    {
	LN_Session *	s;
#line 87 "Session.xs"
      d_LN_XSVARS;
#line 110 "Session.c"

   /* NOTE: ALL O_LN_OBJECT C-types MUST be typedef'ed to SV  */
   if ( sv_isobject( ST(0) ) && ( SvTYPE( SvRV( ST(0) ) ) == SVt_PVMG) ) {
      s = (LN_Session *) ST(0);
   } else {
     warn( "Notes::Session::DESTROY() -- s is not a blessed SV reference" );
     XSRETURN_UNDEF;
   }   ;
#line 89 "Session.xs"
      ln_global_session_count -= 1;   /* NOT threadsafe ! */

      if(ln_global_session_count > 0) /* NOT threadsafe ! */
      {
      	LN_SET_OK(s);
      }
      else
      {
      	session_destroy();
      }

      XSRETURN( 0 );
#line 132 "Session.c"
	PUTBACK;
	return;
    }
}

XS(XS_Notes__Session_session_count)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Notes::Session::session_count(s)");
    SP -= items;
    {
	LN_Session *	s;

   /* NOTE: ALL O_LN_OBJECT C-types MUST be typedef'ed to SV  */
   if ( sv_isobject( ST(0) ) && ( SvTYPE( SvRV( ST(0) ) ) == SVt_PVMG) ) {
      s = (LN_Session *) ST(0);
   } else {
     warn( "Notes::Session::session_count() -- s is not a blessed SV reference" );
     XSRETURN_UNDEF;
   }   ;
#line 107 "Session.xs"
      XSRETURN_IV((long) ln_global_session_count);
#line 156 "Session.c"
	PUTBACK;
	return;
    }
}

XS(XS_Notes__Session_set_session_count)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Notes::Session::set_session_count(s, ln_session_count)");
    SP -= items;
    {
	LN_Session *	s;
	int	ln_session_count = (int)SvIV(ST(1));
#line 115 "Session.xs"
      d_LN_XSVARS;
#line 173 "Session.c"

   /* NOTE: ALL O_LN_OBJECT C-types MUST be typedef'ed to SV  */
   if ( sv_isobject( ST(0) ) && ( SvTYPE( SvRV( ST(0) ) ) == SVt_PVMG) ) {
      s = (LN_Session *) ST(0);
   } else {
     warn( "Notes::Session::set_session_count() -- s is not a blessed SV reference" );
     XSRETURN_UNDEF;
   }   ;
#line 117 "Session.xs"
      ln_global_session_count = ln_session_count;
      XSRETURN(0);
#line 185 "Session.c"
	PUTBACK;
	return;
    }
}

XS(XS_Notes__Session_effective_user_name)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Notes::Session::effective_user_name(s)");
    SP -= items;
    {
	LN_Session *	s;
#line 124 "Session.xs"
	  char		   szUserName[MAXUSERNAME+1];
	  STATUS	   ln_rc = NOERROR;
#line 202 "Session.c"

   /* NOTE: ALL O_LN_OBJECT C-types MUST be typedef'ed to SV  */
   if ( sv_isobject( ST(0) ) && ( SvTYPE( SvRV( ST(0) ) ) == SVt_PVMG) ) {
      s = (LN_Session *) ST(0);
   } else {
     warn( "Notes::Session::effective_user_name() -- s is not a blessed SV reference" );
     XSRETURN_UNDEF;
   }   ;
#line 127 "Session.xs"
	  if (ln_rc = SECKFMGetUserName (szUserName))
	  {
		DEBUG(("Notes::Session object returning error %d at line %d", ln_rc, __LINE__));
	  	XSRETURN_NOT_OK;
      }
      else
      	XPUSHs( sv_2mortal( newSVpv( szUserName, 0 )));
#line 219 "Session.c"
	PUTBACK;
	return;
    }
}

XS(XS_Notes__Session_data_directory)
{
    dXSARGS;
    dXSI32;
    if (items != 1)
       Perl_croak(aTHX_ "Usage: %s(s)", GvNAME(CvGV(cv)));
    SP -= items;
    {
	LN_Session *	s;
#line 139 "Session.xs"
      char   szPathname[MAXPATH];
#line 236 "Session.c"

   /* NOTE: ALL O_LN_OBJECT C-types MUST be typedef'ed to SV  */
   if ( sv_isobject( ST(0) ) && ( SvTYPE( SvRV( ST(0) ) ) == SVt_PVMG) ) {
      s = (LN_Session *) ST(0);
   } else {
     warn( "Notes::Session::data_directory() -- s is not a blessed SV reference" );
     XSRETURN_UNDEF;
   }   ;
#line 144 "Session.xs"
   	  if ( LN_IS_OK(s) )
      {
  	 	  switch( ix )
  	 	  {
			  case 0:    OSGetDataDirectory(szPathname);
			             break;
			  case 1:    OSGetExecutableDirectory(szPathname);
			  		     break;
			  default:   XSRETURN_NOT_OK;
			  			 break;
  		  }
		  XPUSHs( sv_2mortal( newSVpv( szPathname, 0 )));
		  XSRETURN( 1 );
      }
      else
      	XSRETURN_NOT_OK;
#line 262 "Session.c"
	PUTBACK;
	return;
    }
}

XS(XS_Notes__Session_get_environment_value)
{
    dXSARGS;
    dXSI32;
    if (items != 2)
       Perl_croak(aTHX_ "Usage: %s(s, ln_name)", GvNAME(CvGV(cv)));
    SP -= items;
    {
	LN_Session *	s;
	char *	ln_name = (char *)SvPV(ST(1),PL_na);
#line 166 "Session.xs"
      long ln_value;
      char ln_str_value[MAXENVVALUE];
#line 281 "Session.c"

   /* NOTE: ALL O_LN_OBJECT C-types MUST be typedef'ed to SV  */
   if ( sv_isobject( ST(0) ) && ( SvTYPE( SvRV( ST(0) ) ) == SVt_PVMG) ) {
      s = (LN_Session *) ST(0);
   } else {
     warn( "Notes::Session::get_environment_value() -- s is not a blessed SV reference" );
     XSRETURN_UNDEF;
   }   ;
#line 172 "Session.xs"
     if(ln_name != NULL)
     {
         switch(ix)
         {
		     case 0:    ln_value = OSGetEnvironmentLong(ln_name);
		     			if(ln_value)
		     			{
		     				XPUSHs( sv_2mortal( newSViv( ln_value )));
					    }
		     			else
		     			{
		     				XSRETURN_NOT_OK;
					    }
		                break;
			 case 1:    if(OSGetEnvironmentString(ln_name, ln_str_value, MAXENVVALUE - 1))
			 			{
			 				XPUSHs( sv_2mortal( newSVpv( ln_str_value, 0 )));
					    }
			   			else
			   			{
			   				XSRETURN_NOT_OK;
						}
		                break;
			 default:   XSRETURN_NOT_OK;
			 		    break;
         }
     }
     XSRETURN( 1 );
#line 319 "Session.c"
	PUTBACK;
	return;
    }
}

XS(XS_Notes__Session_set_environment_var)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Notes::Session::set_environment_var(s, ln_name, ln_value)");
    SP -= items;
    {
	LN_Session *	s;
	char *	ln_name = (char *)SvPV(ST(1),PL_na);
	char *	ln_value = (char *)SvPV(ST(2),PL_na);

   /* NOTE: ALL O_LN_OBJECT C-types MUST be typedef'ed to SV  */
   if ( sv_isobject( ST(0) ) && ( SvTYPE( SvRV( ST(0) ) ) == SVt_PVMG) ) {
      s = (LN_Session *) ST(0);
   } else {
     warn( "Notes::Session::set_environment_var() -- s is not a blessed SV reference" );
     XSRETURN_UNDEF;
   }   ;
#line 207 "Session.xs"
      if (ln_name != NULL && ln_value != NULL)
      {
      	OSSetEnvironmentVariable(ln_name, ln_value);
      	XSRETURN_YES;
      }
      else
      {
      	XSRETURN_NOT_OK;
      }
#line 353 "Session.c"
	PUTBACK;
	return;
    }
}

XS(XS_Notes__Session_address_books)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Notes::Session::address_books(s, ln_server)");
    SP -= items;
    {
	LN_Session *	s;
	char *	ln_server = (char *)SvPV(ST(1),PL_na);
#line 222 "Session.xs"
      STATUS   ln_rc = NOERROR;
      WORD     wCount;
      WORD     wLength;
      WORD     wEntry;
      WORD     wEntryLen;

      HANDLE   hReturn;
      char   * pszReturn;

      char     achServer[MAXPATH];
      char     achPort[MAXPATH];
      char     achFile[MAXPATH];
#line 381 "Session.c"

   /* NOTE: ALL O_LN_OBJECT C-types MUST be typedef'ed to SV  */
   if ( sv_isobject( ST(0) ) && ( SvTYPE( SvRV( ST(0) ) ) == SVt_PVMG) ) {
      s = (LN_Session *) ST(0);
   } else {
     warn( "Notes::Session::address_books() -- s is not a blessed SV reference" );
     XSRETURN_UNDEF;
   }   ;
#line 235 "Session.xs"
      if(ln_rc = NAMEGetAddressBooks(ln_server,
                                  0,
                                  &wCount,
                                  &wLength,
                                  &hReturn))
      {
		 DEBUG(("Notes::Session object returning error %d at line %d", ln_rc, __LINE__));
         LN_SET_IVX(s, ln_rc);
         XSRETURN_NOT_OK;
      }
      if (!wCount)
       	 XSRETURN_UNDEF;

      pszReturn = OSLock(char, hReturn);

      for (wEntry = 0; wEntry < wCount; wEntry++)
      {
         wEntryLen = strlen(pszReturn);

         OSPathNetParse(pszReturn, achPort, achServer, achFile);

         // if (wOption & NAME_GET_AB_TITLES) {
         // *   * Advance to title. *
         // *   pszReturn += wEntryLen + 1;
         // *   wEntryLen = strlen(pszReturn);
         // * }
         //

         XPUSHs(sv_2mortal(newSVpv(achFile, 0)));
         XPUSHs(sv_2mortal(newSVpv(achServer, 0)));
         XPUSHs(sv_2mortal(newSVpv(achPort, 0)));

         pszReturn += wEntryLen+1;
      }
      OSUnlock(hReturn);
      OSMemFree(hReturn);
#line 427 "Session.c"
	PUTBACK;
	return;
    }
}

XS(XS_Notes__Session_notes_api_version)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Notes::Session::notes_api_version(s)");
    SP -= items;
    {
	LN_Session *	s;

   /* NOTE: ALL O_LN_OBJECT C-types MUST be typedef'ed to SV  */
   if ( sv_isobject( ST(0) ) && ( SvTYPE( SvRV( ST(0) ) ) == SVt_PVMG) ) {
      s = (LN_Session *) ST(0);
   } else {
     warn( "Notes::Session::notes_api_version() -- s is not a blessed SV reference" );
     XSRETURN_UNDEF;
   }   ;
#line 276 "Session.xs"
   	  XPUSHs(sv_2mortal(newSVpv(NOTESAPI_VERSION, 0)));
   	  XSRETURN( 1 );
#line 452 "Session.c"
	PUTBACK;
	return;
    }
}

XS(XS_Notes__Session_notes_build_version)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Notes::Session::notes_build_version(s)");
    SP -= items;
    {
	LN_Session *	s;
#line 283 "Session.xs"
      STATUS   ln_rc   = NOERROR;
      DBHANDLE hdb     = NULLHANDLE;
      WORD     wbuild;
#line 470 "Session.c"

   /* NOTE: ALL O_LN_OBJECT C-types MUST be typedef'ed to SV  */
   if ( sv_isobject( ST(0) ) && ( SvTYPE( SvRV( ST(0) ) ) == SVt_PVMG) ) {
      s = (LN_Session *) ST(0);
   } else {
     warn( "Notes::Session::notes_build_version() -- s is not a blessed SV reference" );
     XSRETURN_UNDEF;
   }   ;
#line 287 "Session.xs"
      if(ln_rc = NSFDbOpen("names.nsf", &hdb))
      {
		DEBUG(("Notes::Session object returning error %d at line %d", ln_rc, __LINE__));
		LN_SET_IVX(s, ln_rc);
      	XSRETURN_NOT_OK;
  	  }
      if(ln_rc = NSFDbGetBuildVersion(hdb, &wbuild))
      {
		DEBUG(("Notes::Session object returning error %d at line %d", ln_rc, __LINE__));
		NSFDbClose(hdb);
		LN_SET_IVX(s, ln_rc);
      	XSRETURN_NOT_OK;
      }
      else
      	if(wbuild >= 1 && wbuild <= 81)
      	{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release 1.0", 0)));
	    }
	    else if(wbuild >= 82 && wbuild <= 93)
	    {
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release 2.0", 0)));
	    }
	    else if(wbuild >= 94 && wbuild <= 118)
			    {
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release 3.0", 0)));
	    }
	    else if(wbuild >= 119 && wbuild <= 136)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release 4.0", 0)));
	    }
	    else if(wbuild == 138)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release 4.1", 0)));
	    }
	    else if(wbuild >= 140 && wbuild <= 145)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release 4.5", 0)));
	    }
	    else if(wbuild >= 140 && wbuild <= 145)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release 4.5", 0)));
	    }
	    else if(wbuild == 147)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release 4.6", 0)));
	    }
	    else if(wbuild == 161)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release 5.0 Beta 1", 0)));
	    }
	    else if(wbuild == 163)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release 5.0 Beta 2", 0)));
	    }
	    else if(wbuild == 166)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release 5.0 - 5.0.11", 0)));
	    }
	    else if(wbuild == 173)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release Rnext Beta 1", 0)));
	    }
	    else if(wbuild == 176)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release Rnext Beta 2", 0)));
	    }
	    else if(wbuild == 178)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release Rnext Beta 3", 0)));
	    }
	    else if(wbuild == 179)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release Rnext Beta 4", 0)));
	    }
	    else if(wbuild == 183)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes 6 Pre-release 1", 0)));
	    }
	    else if(wbuild == 185)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes 6 Pre-release 2", 0)));
	    }
	    else if(wbuild == 190)
		{
			XPUSHs(sv_2mortal(newSVpv("Domino or Notes Release 6", 0)));
	    }
		else
		{
			XSRETURN_UNDEF;
		}
      NSFDbClose(hdb);
      XSRETURN( 1 );
#line 572 "Session.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Notes__Session)
{
    dXSARGS;
    char* file = __FILE__;

    XS_VERSION_BOOTCHECK ;

    {
        CV * cv ;

        newXS("Notes::Session::new", XS_Notes__Session_new, file);
        newXS("Notes::Session::DESTROY", XS_Notes__Session_DESTROY, file);
        newXS("Notes::Session::session_count", XS_Notes__Session_session_count, file);
        newXS("Notes::Session::set_session_count", XS_Notes__Session_set_session_count, file);
        newXS("Notes::Session::effective_user_name", XS_Notes__Session_effective_user_name, file);
        cv = newXS("Notes::Session::exec_directory", XS_Notes__Session_data_directory, file);
        XSANY.any_i32 = 1 ;
        cv = newXS("Notes::Session::data_directory", XS_Notes__Session_data_directory, file);
        XSANY.any_i32 = 0 ;
        cv = newXS("Notes::Session::get_environment_value", XS_Notes__Session_get_environment_value, file);
        XSANY.any_i32 = 0 ;
        cv = newXS("Notes::Session::get_environment_string", XS_Notes__Session_get_environment_value, file);
        XSANY.any_i32 = 1 ;
        newXS("Notes::Session::set_environment_var", XS_Notes__Session_set_environment_var, file);
        newXS("Notes::Session::address_books", XS_Notes__Session_address_books, file);
        newXS("Notes::Session::notes_api_version", XS_Notes__Session_notes_api_version, file);
        newXS("Notes::Session::notes_build_version", XS_Notes__Session_notes_build_version, file);
    }
    XSRETURN_YES;
}
