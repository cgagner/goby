// copyright 2011 t. schneider tes@mit.edu
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this software.  If not, see <http://www.gnu.org/licenses/>.

#ifndef LIAISONSCOPE20110609H
#define LIAISONSCOPE20110609H

#include <Wt/WText>
#include <Wt/WCssDecorationStyle>
#include <Wt/WBorder>
#include <Wt/WColor>

#include "goby/moos/libmoos_util/moos_node.h"

#include "liaison.h"

namespace Wt
{
    class WStandardItemModel;
}

namespace goby
{
    namespace core
    {
        class LiaisonScope : public LiaisonContainer, public goby::moos::MOOSNode
        
          public:
            LiaisonScope(ZeroMQService* service);
            
            void moos_inbox(CMOOSMsg& msg);
            
          private:
            Wt::WStandardItemModel* model_;
            Wt::WText* text_;
        };
    }
}

#endif