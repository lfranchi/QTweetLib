/* Copyright (c) 2010, Antonie Jovanoski
 *
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Contact e-mail: Antonie Jovanoski <minimoog77_at_gmail.com>
 */

#ifndef QTWEETLISTGETMEMBERS_H
#define QTWEETLISTGETMEMBERS_H

#include "qtweetnetbase.h"

/**
 *   Gets the members of the specified list.
 */
class QTWEETLIBSHARED_EXPORT QTweetListGetMembers : public QTweetNetBase
{
    Q_OBJECT
public:
    QTweetListGetMembers(QObject *parent = 0);
    QTweetListGetMembers(OAuthTwitter *oauthTwitter, QObject *parent = 0);
    void get(qint64 user,
             qint64 list,
             const QString &cursor = QString(),
             bool includeEntities = false);

signals:
    /** Emits page of users
     *  @param users list of users
     *  @param nextCursor cursor for next page, "0" if there is no next page
     *  @param prevCursor cursor for prev page, "0" if there is no prev page
     */
    void parsedUsers(const QList<QTweetUser>& users,
                     const QString& nextCursor,
                     const QString& prevCursor);

protected slots:
    void parsingJsonFinished(const QVariant &json, bool ok, const QString &errorMsg);
};

#endif // QTWEETLISTGETMEMBERS_H
