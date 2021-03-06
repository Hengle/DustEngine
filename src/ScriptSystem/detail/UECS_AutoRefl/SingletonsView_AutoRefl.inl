// This file is generated by Ubpa::USRefl::AutoRefl

#pragma once

#include <USRefl/USRefl.h>

template<>
struct Ubpa::USRefl::TypeInfo<Ubpa::UECS::SingletonsView>
    : Ubpa::USRefl::TypeInfoBase<Ubpa::UECS::SingletonsView>
{
    static constexpr AttrList attrs = {};

    static constexpr FieldList fields = {
        Field{Name::constructor, WrapConstructor<Ubpa::UECS::SingletonsView(const Ubpa::UECS::CmptPtr *, size_t)>(),
            AttrList {
                Attr{UBPA_USREFL_NAME_ARG(0),
                    AttrList{
                        Attr{Name::name, "singletons"},
                    }
                },
                Attr{UBPA_USREFL_NAME_ARG(1),
                    AttrList{
                        Attr{Name::name, "num"},
                    }
                },
            }
        },
        Field{"GetSingleton", &Ubpa::UECS::SingletonsView::GetSingleton,
            AttrList {
                Attr{UBPA_USREFL_NAME_ARG(0)},
            }
        },
        Field{"Singletons", &Ubpa::UECS::SingletonsView::Singletons},
        Field{"NumberOfSingletons", &Ubpa::UECS::SingletonsView::NumberOfSingletons},
    };
};

