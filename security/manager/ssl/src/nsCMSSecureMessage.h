/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla Communicator.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corp..
 * Portions created by the Initial Developer are Copyright (C) 2001
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s): Terry Hayes <thayes@netscape.com>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef _NSCMSSECUREMESSAGE_H_
#define _NSCMSSECUREMESSAGE_H_

#include "nsICMSSecureMessage.h"

#include "cms.h"

// ===============================================
// nsCMSManager - implementation of nsICMSManager
// ===============================================

#define NS_CMSSECUREMESSAGE_CLASSNAME "CMS Secure Message"
#define NS_CMSSECUREMESSAGE_CID \
  { 0x5fb907e0, 0x1dd2, 0x11b2, { 0xa7, 0xc0, 0xf1, 0x4c, 0x41, 0x6a, 0x62, 0xa1 } }

class nsCMSSecureMessage
: public nsICMSSecureMessage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICMSSECUREMESSAGE

  nsCMSSecureMessage();
  virtual ~nsCMSSecureMessage();

private:
  NS_METHOD encode(const unsigned char *data, PRInt32 dataLen, char **_retval);
  NS_METHOD decode(const char *data, unsigned char **result, PRInt32 * _retval);
};


#endif /* _NSCMSMESSAGE_H_ */