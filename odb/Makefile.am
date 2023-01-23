# file      : odb/Makefile.am
# license   : GNU GPL v2; see accompanying LICENSE file

cxx =                   \
    exceptions.cxx           \
    database.cxx             \
    vector-impl.cxx          \
    connection.cxx           \
    prepared-query.cxx       \
    query-dynamic.cxx        \
    result.cxx               \
    schema-catalog.cxx       \
    section.cxx              \
    session.cxx              \
    statement.cxx            \
    statement-processing.cxx \
    tracer.cxx               \
    transaction.cxx

# Implementation details.
#
cxx +=                      \
    details/buffer.cxx          \
    details/condition.cxx       \
    details/lock.cxx            \
    details/mutex.cxx           \
    details/shared-ptr/base.cxx

# POSIX-based implementation details.
#
posix_thr_cxx =             \
    details/posix/exceptions.cxx \
    details/posix/thread.cxx

posix_threads_headers = \
    details/posix/condition.hxx \
    details/posix/condition.ixx \
    details/posix/exceptions.hxx \
    details/posix/mutex.hxx \
    details/posix/mutex.ixx \
    details/posix/thread.hxx \
    details/posix/thread.ixx \
    details/posix/tls.hxx \
    details/posix/tls.ixx \
    details/posix/tls.txx

# Win32-based implementation details.
#
win32_thr_cxx =             \
    details/win32/init.cxx       \
    details/win32/once.cxx       \
    details/win32/tls.cxx        \
    details/win32/condition.cxx  \
    details/win32/thread.cxx     \
    details/win32/exceptions.cxx

win32_threads_headers = \
    details/win32/condition.hxx \
    details/win32/condition.ixx \
    details/win32/exceptions.hxx \
    details/win32/init.hxx \
    details/win32/lock.hxx \
    details/win32/mutex.hxx \
    details/win32/mutex.ixx \
    details/win32/once-init.hxx \
    details/win32/once.hxx \
    details/win32/once.ixx \
    details/win32/thread.hxx \
    details/win32/tls-init.hxx \
    details/win32/tls.hxx \
    details/win32/tls.ixx \
    details/win32/tls.txx \
    details/win32/windows.hxx

win32_dll_cxx = details/win32/dll.cxx

win32_headers = details/win32/windows.hxx

cxx_tun = $(cxx)

lib_LTLIBRARIES = libodb.la
libodb_la_SOURCES = $(cxx)

odbincludedir = $(includedir)/odb
nobase_odbinclude_HEADERS = \
    c-array-traits.hxx \
    cache-traits.hxx \
    callback.hxx \
    connection.hxx \
    connection.ixx \
    connection.txx \
    container-traits.hxx \
    core.hxx \
    database.hxx \
    database.ixx \
    database.txx \
    details/buffer.hxx \
    details/c-string.hxx \
    details/condition.hxx \
    details/config.hxx \
    details/exception.hxx \
    details/export.hxx \
    details/function-wrapper.hxx \
    details/function-wrapper.ixx \
    details/function-wrapper.txx \
    details/lock.hxx \
    details/meta/answer.hxx \
    details/meta/class-p.hxx \
    details/meta/polymorphic-p.hxx \
    details/meta/remove-const-volatile.hxx \
    details/meta/remove-const.hxx \
    details/meta/remove-pointer.hxx \
    details/meta/remove-volatile.hxx \
    details/meta/static-assert.hxx \
    details/mutex.hxx \
    details/shared-ptr-fwd.hxx \
    details/shared-ptr.hxx \
    details/shared-ptr/base.hxx \
    details/shared-ptr/base.ixx \
    details/shared-ptr/base.txx \
    details/shared-ptr/counter-type.hxx \
    details/shared-ptr/exception.hxx \
    details/thread.hxx \
    details/tls.hxx \
    details/transfer-ptr.hxx \
    details/type-info.hxx \
    details/unique-ptr.hxx \
    details/unused.hxx \
    details/wrapper-p.hxx \
    exception.hxx \
    exceptions.hxx \
    forward.hxx \
    function-table.hxx \
    lazy-pointer-traits.hxx \
    lazy-ptr-impl.hxx \
    lazy-ptr-impl.ixx \
    lazy-ptr-impl.txx \
    lazy-ptr.hxx \
    lazy-ptr.ixx \
    lazy-ptr.txx \
    nested-container.hxx \
    no-id-object-result.hxx \
    no-id-object-result.txx \
    no-op-cache-traits.hxx \
    nullable.hxx \
    object-result.hxx \
    pointer-traits.hxx \
    polymorphic-info.hxx \
    polymorphic-map.hxx \
    polymorphic-map.ixx \
    polymorphic-map.txx \
    polymorphic-object-result.hxx \
    polymorphic-object-result.txx \
    post.hxx \
    pre.hxx \
    prepared-query.hxx \
    query-dynamic.hxx \
    query-dynamic.ixx \
    query-dynamic.txx \
    query.hxx \
    result.hxx \
    result.txx \
    schema-catalog-impl.hxx \
    schema-catalog.hxx \
    schema-version.hxx \
    section.hxx \
    session.hxx \
    session.ixx \
    session.txx \
    simple-object-result.hxx \
    simple-object-result.txx \
    statement-processing-common.hxx \
    statement.hxx \
    std-array-traits.hxx \
    std-deque-traits.hxx \
    std-forward-list-traits.hxx \
    std-list-traits.hxx \
    std-map-traits.hxx \
    std-set-traits.hxx \
    std-unordered-map-traits.hxx \
    std-unordered-set-traits.hxx \
    std-vector-traits.hxx \
    tr1/lazy-pointer-traits.hxx \
    tr1/lazy-ptr.hxx \
    tr1/lazy-ptr.ixx \
    tr1/lazy-ptr.txx \
    tr1/memory.hxx \
    tr1/pointer-traits.hxx \
    tr1/wrapper-traits.hxx \
    tracer.hxx \
    traits.hxx \
    transaction.hxx \
    transaction.ixx \
    vector-impl.hxx \
    vector-impl.ixx \
    vector-traits.hxx \
    vector-traits.txx \
    vector.hxx \
    vector.ixx \
    version-build2-stub.hxx \
    version-build2.hxx \
    version.hxx \
    view-image.hxx \
    view-result.hxx \
    view-result.txx \
    wrapper-traits.hxx

nobase_nodist_odbinclude_HEADERS = details/config.h

EXTRA_DIST = details/config.h.in details/config-vc.h \
    libodb-vc8.vcproj libodb-vc9.vcproj \
    libodb-vc10.vcxproj libodb-vc10.vcxproj.filters \
    libodb-vc11.vcxproj libodb-vc11.vcxproj.filters \
    libodb-vc12.vcxproj libodb-vc12.vcxproj.filters


# At the moment, DllMain() is only necessary if we are using Win32
# threads. So keep win32_dll_sources in ODB_THREADS_WIN32.
#
if ODB_WIN32
nobase_odbinclude_HEADERS += $(win32_headers)
endif

if ODB_THREADS_POSIX
libodb_la_SOURCES += $(posix_thr_cxx)
nobase_odbinclude_HEADERS += $(posix_threads_headers)
endif

if ODB_THREADS_WIN32
libodb_la_SOURCES += $(win32_thr_cxx) $(win32_dll_cxx)
nobase_odbinclude_HEADERS += $(win32_threads_headers)
endif

libodb_la_CPPFLAGS = -DLIBODB_DYNAMIC_LIB
libodb_la_LDFLAGS = -release @INTERFACE_VERSION@ -no-undefined
