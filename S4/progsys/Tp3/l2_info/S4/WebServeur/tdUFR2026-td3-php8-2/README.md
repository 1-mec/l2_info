cp .env.example .env
# put your own setting in .env APP_NAME, APP_LOCALE, APP_FAKER_LOCALE, LOG_CHANNEL
# run composer install
composer install
# run npm install
npm install
# generate your key
php artisan key:generate
# migration
php artisan migrate:fresh --seed
