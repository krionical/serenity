/*
 * Copyright (c) 2022, Simon Danner <danner.simon@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/SVG/SVGDefsElement.h>

namespace Web::SVG {

SVGDefsElement::SVGDefsElement(DOM::Document& document, DOM::QualifiedName qualified_name)
    : SVGGraphicsElement(document, move(qualified_name))
{
}

SVGDefsElement::~SVGDefsElement()
{
}

JS::ThrowCompletionOr<void> SVGDefsElement::initialize(JS::Realm& realm)
{
    MUST_OR_THROW_OOM(Base::initialize(realm));
    set_prototype(&Bindings::ensure_web_prototype<Bindings::SVGDefsElementPrototype>(realm, "SVGDefsElement"));

    return {};
}

JS::GCPtr<Layout::Node> SVGDefsElement::create_layout_node(NonnullRefPtr<CSS::StyleProperties>)
{
    return nullptr;
}

}
