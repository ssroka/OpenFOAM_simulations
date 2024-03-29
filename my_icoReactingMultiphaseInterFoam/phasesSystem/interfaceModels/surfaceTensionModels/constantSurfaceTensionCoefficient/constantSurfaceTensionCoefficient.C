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

\*---------------------------------------------------------------------------*/

#include "constantSurfaceTensionCoefficient.H"
#include "phasePair.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace surfaceTensionModels
{
    defineTypeNameAndDebug(constantSurfaceTensionCoefficient, 0);
    addToRunTimeSelectionTable
    (
        surfaceTensionModel,
        constantSurfaceTensionCoefficient,
        dictionary
    );
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::surfaceTensionModels::constantSurfaceTensionCoefficient::
constantSurfaceTensionCoefficient
(
    const dictionary& dict,
    const phasePair& pair,
    const bool registerObject
)
:
    surfaceTensionModel(dict, pair, registerObject),
    sigma_("sigma", dimensionSet(1, 0, -2, 0, 0), dict.lookup("sigma"))
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::surfaceTensionModels::constantSurfaceTensionCoefficient::sigma() const
{
    const fvMesh& mesh(this->pair_.phase1().mesh());

    return
        tmp<volScalarField>::New
        (
            IOobject
            (
                "zero",
                mesh.time().timeName(),
                mesh
            ),
            mesh,
            sigma_
        );
}


// ************************************************************************* //
