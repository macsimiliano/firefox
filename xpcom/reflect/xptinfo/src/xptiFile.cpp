/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
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
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1999
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Mike McCabe <mccabe@netscape.com>
 *   John Bandhauer <jband@netscape.com>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either of the GNU General Public License Version 2 or later (the "GPL"),
 * or the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
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

/* Implementation of xptiFile. */

#include "xptiprivate.h"

xptiFile::xptiFile()
    :   
#ifdef DEBUG
        mDEBUG_WorkingSet(nsnull),
#endif
        mSize(),
        mDate(),
        mName(nsnull),
        mGuts(nsnull),
        mDirectory(0)
{
    // empty
    MOZ_COUNT_CTOR(xptiFile);
}

xptiFile::xptiFile(const nsInt64&  aSize,
         const nsInt64&  aDate,
         PRUint32        aDirectory,
         const char*     aName,
         xptiWorkingSet* aWorkingSet)
    :   
#ifdef DEBUG
        mDEBUG_WorkingSet(aWorkingSet),
#endif
        mSize(aSize),
        mDate(aDate),
        mName(aName),
        mGuts(nsnull),
        mDirectory(aDirectory)
{
    NS_ASSERTION(aWorkingSet,"bad param");
    mName = XPT_STRDUP(aWorkingSet->GetStringArena(), aName);

    MOZ_COUNT_CTOR(xptiFile);
}

xptiFile::xptiFile(const xptiFile& r, xptiWorkingSet* aWorkingSet)
    :   
#ifdef DEBUG
        mDEBUG_WorkingSet(aWorkingSet),
#endif
        mSize(r.mSize),
        mDate(r.mDate),
        mName(nsnull),
        mGuts(nsnull),
        mDirectory(r.mDirectory)
{
    NS_ASSERTION(aWorkingSet,"bad param");
    mName = XPT_STRDUP(aWorkingSet->GetStringArena(), r.mName);

    MOZ_COUNT_CTOR(xptiFile);
}

xptiFile::~xptiFile()
{
    MOZ_COUNT_DTOR(xptiFile);
}

PRBool 
xptiFile::SetHeader(XPTHeader* aHeader, xptiWorkingSet* aWorkingSet)
{
    NS_ASSERTION(!mGuts,"bad state");
    NS_ASSERTION(aHeader,"bad param");
    NS_ASSERTION(aWorkingSet,"bad param");

    mGuts = xptiTypelibGuts::NewGuts(aHeader, aWorkingSet);
    return mGuts != nsnull;
}
