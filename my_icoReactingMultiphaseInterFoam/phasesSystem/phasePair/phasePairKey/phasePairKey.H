/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2017 OpenCFD Ltd.
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::phasePairKey

Description

SourceFiles

\*---------------------------------------------------------------------------*/

#ifndef phasePairKey_H
#define phasePairKey_H

#include "Pair.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                         Class phasePairKey Declaration
\*---------------------------------------------------------------------------*/

class phasePairKey
:
    public Pair<word>
{
public:

        class hash
        :
            public Hash<phasePairKey>
        {
        public:

            // Constructors

                //- Construct null
                hash();


            // Member operators

                //- Generate a hash from a phase pair key
                label operator()(const phasePairKey& key) const;
        };


private:

    // Private data

        //- Flag to indicate whether ordering is important
        bool ordered_;


public:

    // Constructors

        //- Construct null
        phasePairKey();

        //- Construct from names and the ordering flag
        phasePairKey
        (
            const word& name1,
            const word& name2,
            const bool ordered = false
        );


    // Destructor
    virtual ~phasePairKey() = default;


    // Access

        //- Return the ordered flag
        bool ordered() const;


    // Friend Operators

        //- Test if keys are equal
        friend bool operator==(const phasePairKey& a, const phasePairKey& b);

        //- Test if keys are unequal
        friend bool operator!=(const phasePairKey& a, const phasePairKey& b);

        //- Read from stdin
        friend Istream& operator>>(Istream& is, phasePairKey& key);

        //- Write to stdout
        friend Ostream& operator<<(Ostream& os, const phasePairKey& key);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
