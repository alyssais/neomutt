/**
 * @file
 * Representation of a mailbox
 *
 * @authors
 * Copyright (C) 1996-2000,2010,2013 Michael R. Elkins <me@mutt.org>
 * Copyright (C) 2018 Richard Russon <rich@flatcap.org>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MUTT_ACCOUNT_H
#define MUTT_ACCOUNT_H

#include "mutt/queue.h"
#include "config/lib.h"
#include "mailbox.h"

struct ConnAccount;

/**
 * struct Account - XXX
 */
struct Account
{
  enum MailboxType magic;
  struct MailboxList mailboxes;
  TAILQ_ENTRY(Account) entries;
  void *adata;
  void (*free_adata)(void **);
};

TAILQ_HEAD(AccountList, Account);

extern struct AccountList AllAccounts; ///< List of all Accounts

struct Account *account_new(void);
void            account_remove_mailbox(struct Account *a, struct Mailbox *m);

#endif /* MUTT_ACCOUNT_H */
