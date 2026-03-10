<x-app-layout>
    <x-slot name="header">
        <h2 class="font-semibold text-xl text-gray-800 leading-tight">
            {{ __('Video') }}: {{ $video->title }}
        </h2>
    </x-slot>

    <div class="py-12">
        <div class="max-w-7xl mx-auto sm:px-6 lg:px-8">
            <div class="bg-white overflow-hidden shadow-sm sm:rounded-lg">
                <div class="p-6 text-gray-900">
                    <div class="rounded-xl"><!-- image --></div>
                    <div>
                        <p class="font-bold text-xl">{{ $video->title }}</p>
                        <p>{{ $video->description }}</p>
                        <p>{{ $video->year }} - {{ $video->price }}€</p>
                    </div>
                </div>
            </div>
        </div>
    </div>
</x-app-layout>
