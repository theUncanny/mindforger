/*
 organizer_presenter.h     MindForger thinking notebook

 Copyright (C) 2016-2018 Martin Dvorak <martin.dvorak@mindforger.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef M8RUI_ORGANIZER_PRESENTER_H
#define M8RUI_ORGANIZER_PRESENTER_H

#include <vector>

#include <QtWidgets>

#include "organizer_view.h"
#include "organizer_quadrant_presenter.h"

namespace m8r {

class OrganizerQuadrantPresenter;
class OrlojPresenter;

class OrganizerPresenter : public QObject
{
    Q_OBJECT

    OrganizerView* view;

    OrganizerQuadrantPresenter* doFirstPresenter;
    OrganizerQuadrantPresenter* doSoonPresenter;
    OrganizerQuadrantPresenter* doSometimePresenter;
    OrganizerQuadrantPresenter* planDedicatedTimePresenter;

public:
    explicit OrganizerPresenter(OrganizerView* view, OrlojPresenter* orloj);
    OrganizerPresenter(const OrganizerPresenter&) = delete;
    OrganizerPresenter(const OrganizerPresenter&&) = delete;
    OrganizerPresenter &operator=(const OrganizerPresenter&) = delete;
    OrganizerPresenter &operator=(const OrganizerPresenter&&) = delete;
    ~OrganizerPresenter();

    void refresh(const std::vector<Outline*>& os);
};

}
#endif // M8RUI_ORGANIZER_PRESENTER_H
