    Info<< "Reading wave pressure field p_w\n" << endl;
    volScalarField p_w
    (
        IOobject
        (
            "p_w",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field U\n" << endl;
    volVectorField U
    (
        IOobject
        (
            "U",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );


    volScalarField* Tptr = NULL;

    if (thermalStress)
    {
        Info<< "Reading field T\n" << endl;
        Tptr = new volScalarField
        (
            IOobject
            (
                "T",
                runTime.timeName(),
                mesh,
                IOobject::MUST_READ,
                IOobject::AUTO_WRITE
            ),
            mesh
        );
    }

    volScalarField& T = *Tptr;
