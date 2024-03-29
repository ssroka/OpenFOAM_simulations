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
    Foam::phasePair description for mass transfer between a pair of
    phases. The direction of the mass transfer is from the phase
    'from' to the phasse 'to'.

Description

SourceFiles
    phasePair.C

\*---------------------------------------------------------------------------*/

#ifndef phasePair_H
#define phasePair_H

#include "phaseModel.H"
#include "phasePairKey.H"
#include "uniformDimensionedFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                         Class phasePair Declaration
\*---------------------------------------------------------------------------*/

class phasePair
:
    public phasePairKey
{
    // Private data

        //- Phase 1
        const phaseModel& phase1_;

        //- Phase 2
        const phaseModel& phase2_;


public:

    // Constructors

        //- Construct from two phases
        phasePair
        (
            const phaseModel& phase1,
            const phaseModel& phase2,
            const bool ordered = false
        );


    //- Destructor
    virtual ~phasePair() = default;


    // Member Functions

        //- From phase
        virtual const phaseModel& from() const;

        //- To phase
        virtual const phaseModel& to() const;

        //- Pair name
        virtual word name() const;


        // Access

            // Phase 1
            inline const phaseModel& phase1() const;

            // Phase 2
            inline const phaseModel& phase2() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "phasePairI.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
