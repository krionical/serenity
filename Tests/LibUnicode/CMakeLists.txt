set(TEST_SOURCES
    TestEmoji.cpp
    TestSegmentation.cpp
    TestUnicodeCharacterTypes.cpp
    TestUnicodeNormalization.cpp
)

foreach(source IN LISTS TEST_SOURCES)
    serenity_test("${source}" LibUnicode LIBS LibUnicode)

    get_filename_component(target "${source}" NAME_WLE)
endforeach()
